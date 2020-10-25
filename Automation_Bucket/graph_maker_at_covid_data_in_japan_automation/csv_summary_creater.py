import pandas as pd

import os
import shutil
import glob
import time
import csv
import datetime
import dateutil.parser

# Set folder path
csv_download_dir = './csv_download'
csv_format_dir = './csv_format'
summary_csv_path = './covid_summary_data_in_japan.csv'

def csvSummaryCreater():
    csvFormater()

    merge_data = []
    format_csvfile_paths = [
        f'{csv_format_dir}/pcr_positive_daily.csv',  # Number of positives
        f'{csv_format_dir}/pcr_tested_daily.csv',    # Number of inspections
        f'{csv_format_dir}/severe_daily.csv',        # Number of serious injuries
        f'{csv_format_dir}/recovery_total.csv',      # Number of recovers
        f'{csv_format_dir}/death_total.csv',         # Number of deaths
    ]

    for format_csvfile_path in format_csvfile_paths:
        if os.path.isfile(format_csvfile_path):
            merge_data.append(pd.read_csv(format_csvfile_path))
    
    # Combine data and create CSV file
    df_concat = pd.concat(merge_data, axis=1)
    df_concat.to_csv(summary_csv_path,index=None)

def csvFormater():
    # Get CSV file path list
    download_file_names = glob.glob(f'{csv_download_dir}/*.csv')

    # Creating a folder for formatting
    if os.path.isdir(csv_format_dir):
        shutil.rmtree(csv_format_dir)
    os.mkdir(csv_format_dir)

    csvfile_paths = [
        f'{csv_download_dir}/pcr_positive_daily.csv',  # Number of positives
        f'{csv_download_dir}/pcr_tested_daily.csv',    # Number of inspections
        f'{csv_download_dir}/severe_daily.csv',        # Number of serious injuries
        f'{csv_download_dir}/recovery_total.csv',      # Number of recovers
        f'{csv_download_dir}/death_total.csv',         # Number of deaths
    ]

    # CSV file formatting
    head_flag = True
    for csvfile_path in csvfile_paths:
        if csvfile_path in download_file_names:
            csvFormatCreate(csvfile_path,head_flag)
            head_flag = False

def csvFormatCreate(file_path:str, head_flag:bool):   
    # Get CSV file name and make format csv file path
    file_name = file_path.replace(f'{csv_download_dir}/','')
    format_csv_path = f'{csv_format_dir}/{file_name}'

    with open(format_csv_path, 'w') as w:
        writer = csv.writer(w)
        with open(file_path) as f:
            reader = csv.reader(f)

            # Convert to list type
            reader = [row for row in reader]

            # Extract the header
            header = reader.pop(0)

            # Write header
            if head_flag:
                writer.writerow(header)
            else:
                writer.writerow(header[1:])
            
            # Write content in format csv
            for row in reader:
                # Data specification by date range
                row[0] = dateutil.parser.parse(row[0]).strftime("%Y/%m/%d")
                day = int(dateutil.parser.parse(row[0]).strftime("%d"))
                before_5day = (datetime.datetime.now()-datetime.timedelta(days=5)).strftime("%Y/%m/%d")

                if '2020/03/01' <= row[0] <= before_5day and day%10==0:
                    if head_flag:
                        writer.writerow(row)
                    else:
                        writer.writerow(row[1:])


if __name__ == "__main__":
    csvSummaryCreater()