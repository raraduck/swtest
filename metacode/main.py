import sys
import argparse
import os
import requests
import pandas as pd
from dotenv import load_dotenv

def get_access_token(consumer_key, consumer_secret):
    pass

def get_data_from_api(adm_cd, year):
    pass

def save_file(content, file_name, file_type):
    pass

def upload_to_s3(file_name, bucket_name, object_name):
    pass

def main(args):
    # 변수 설정 get_access_token
    load_dotenv()
    api_key = os.getenv("API_KEY")
    print(api_key)

    # 1. API를 통해서 데이터 가져오기 get_data_from_api
    # "https://sgisapi.kostat.go.kr/OpenAPI3/stats/population.json?year=2022&low_search=1&adm_cd=11040&accessToken=09b7aef4-4874-4ff6-affa-7727d7466c29"
    # "https://sgisapi.kostat.go.kr/OpenAPI3/stats/population.json?year=2022&low_search=1&adm_cd=11040&accessToken=09b7aef4-4874-4ff6-affa-7727d7466c29"
    url = "https://sgisapi.kostat.go.kr/OpenAPI3/stats/population.json"
    url += '?year=' + str(args.year)  # 전체데이터로 변경
    url += "&adm_cd=" + str(args.adm_cd)  # 필요한 조회일 등록
    url += "&low_search=1"
    url += "&accessToken=" + str(api_key)  # 필요한 조회일 등록
    print(url)
    response = requests.get(url)
    print(response)
    print(response.text)

    # 2. 데이터 가공하기
    # 3. 데이터를 파일로 저장하고 S3에 업로드하기
    pass

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




