import sys
import argparse
import os
import requests
import json
import jsonlines
import pandas as pd
import boto3
from dotenv import load_dotenv

def get_access_token(consumer_key, consumer_secret):
    url = "https://sgisapi.kostat.go.kr/OpenAPI3/auth/authentication.json"
    url += f"?consumer_key={consumer_key}" # 전체데이터로 변경
    url += f"&consumer_secret={consumer_secret}"  # 필요한 조회일 등록
    response = requests.get(url)
    res = response.json()
    if res['errCd']==0:
        print('API_KEY 획득 성공')
        api_key = res['result']['accessToken']
    else:
        print(f'에러발생: {res["errMsg"]}')
        sys.exit(1)
    return api_key

def get_data_from_api(adm_cd, year):
    consumer_key = os.getenv("CONSUMER_KEY")
    consumer_secret = os.getenv("CONSUMER_SECRET")
    api_key = get_access_token(consumer_key, consumer_secret)
    url = "https://sgisapi.kostat.go.kr/OpenAPI3/stats/population.json"
    url += '?year=' + str(year)  # 전체데이터로 변경
    url += "&adm_cd=" + str(adm_cd)  # 필요한 조회일 등록
    url += "&low_search=1"
    url += "&accessToken=" + str(api_key)  # 필요한 조회일 등록
    response = requests.get(url)
    res = response.json()
    if res['errCd']==0:
        return res['result']
    elif res['errCd']==-401:
        print(res['errMsg'])
        return None
    else:
        print(f'에러발생: {res["errMsg"]}')
        sys.exit(1)

def save_file(content, file_name, file_type):
    if file_type == 'json':
        with jsonlines.open(file_name, "w") as f:
            f.write_all(content)
    elif file_type == "json-test":
        with open(file_name, "w", encoding="utf-8") as f:
            json_str = json.dumps(content, ensure_ascii=False, separators=(",", ":"))
            json_str = json_str.replace("[", "[\n").replace("]", "\n]").replace("{", "\t{").replace("},", "},\n")
            f.write(json_str)
    elif file_type == 'csv-test':
        df = pd.DataFrame(content)
        df.to_csv(file_name, index=False, encoding="utf-8-sig")  # utf-8-sig는 엑셀 호환성 ↑
    else:
        print(f"FileType ({file_type}) is not supported")
        sys.exit(1)
    print(f"{file_name}.{file_type} 파일 저장 완료")

def upload_to_s3(file_name, bucket_name, object_name):
    from botocore.exceptions import NoCredentialsError
    AWS_ACCESS_KEY_ID = os.getenv("AWS_ACCESS_KEY_ID")
    AWS_SECRET_ACCESS_KEY = os.getenv("AWS_SECRET_ACCESS_KEY")
    AWS_DEFAULT_REGION = os.getenv("AWS_DEFAULT_REGION")
    s3_client = boto3.client("s3",
                             aws_access_key_id=AWS_ACCESS_KEY_ID,
                             aws_secret_access_key=AWS_SECRET_ACCESS_KEY,
                             region_name=AWS_DEFAULT_REGION,
                             )
    try:
        s3_client.upload_file(file_name, bucket_name, object_name)
    except NoCredentialsError:
        print("AWS 자격 증명을 찾을 수 없습니다.")

def main(args):
    load_dotenv()
    # 1. API를 통해서 데이터 가져오기 
    data = get_data_from_api(args.adm_cd, args.year)
    # 2. 데이터를 파일로 저장
    file_name = f"{args.year}_{args.adm_cd}_result.json"
    save_file(data, file_name, "json")
    # 3. S3에 업로드하기
    bucket_name = "metacode-dwngcp"
    object_name = f"population-raw/year={args.year}/adm_cd={args.adm_cd}/result.json"
    upload_to_s3(file_name, bucket_name, object_name)



if __name__ == "__main__":
    sys_argv = sys.argv[1:]
    # print(sys_argv)
    if len(sys_argv) > 0:
        parser = argparse.ArgumentParser()
        parser.add_argument('-i', '--init', type=str, choices=['y','n'], required=True, help="데이터 수집 초기 여부 (y = Yes, n = No, required)")
        parser.add_argument('-a', '--adm_cd', type=str, default='non', help="행정구역 코드 (5자리), default: non (전국구))")
        parser.add_argument('-y', '--year', type=str, default='2023', help="기준연도, default: 2023)")
        args = parser.parse_args(sys_argv)
        # print(args)
        main(args)
    else:
        print("Arguments required: -i, -a, -y")




