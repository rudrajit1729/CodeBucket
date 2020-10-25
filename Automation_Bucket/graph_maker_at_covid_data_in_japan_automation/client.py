from csv_downloader import csvDownloader
from csv_summary_creater import csvSummaryCreater
from graph_maker import graphMaker

def main():
    try:
        csvDownloader()
    except:
        print('CSV download failure....')
        exit()

    try:
        csvSummaryCreater()
    except:
        print('create summary csv failure....')
        exit()
    
    try:
        graphMaker()
    except:
        print('graph make failure....')
        exit()
    
    print('complete!!')

if __name__ == "__main__":
    main()

