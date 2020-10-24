def main():
    try:
        csvDownloader()
    except:
        print('CSV download failure....')

    try:
        csvformater()
    except:
        print('CSV format failure....')
    
    try:
        graphMaker()
    except:
        print('graph make failure....')

if __name__ == "__main__":
    main()

