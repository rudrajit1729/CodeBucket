import pandas as pd
import matplotlib
import matplotlib.pyplot as plt
import japanize_matplotlib

import os

# Set the summary csv file path
summary_csv_path = './covid_summary_data_in_japan.csv'

def graphMaker():
    # Check if there is a file. If not, an exception will occur
    if os.path.isfile(summary_csv_path):
        plt.style.use('ggplot') 

        # Extract data from CSV file
        df = pd.read_csv(summary_csv_path, index_col=0)

        # Create a frame for the graph
        plt.figure()

        # Legend creation
        df.plot.bar()
        plt.legend(loc="upper left", fontsize=7)

        # Create graph label
        plt.title('Changes the effects of Covid in Japan', fontsize=14)
        plt.xlabel('Date', fontsize=14)
        plt.ylabel("Number", fontsize=14)

        # Save and show
        plt.savefig('./graph_covid_in_japan.png')
        plt.show()
        plt.close('all')
    else:
        raise Exception


if __name__ == "__main__":
    graphMaker()