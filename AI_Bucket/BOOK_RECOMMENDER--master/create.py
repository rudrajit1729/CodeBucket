#import lib
import pandas as pd

#load data
data = pd.read_csv("books.csv")
print(data.loc[0])

#drop un wanted data columns
d = data.drop(['isbn13','isbn10','subtitle','thumbnail','published_year','num_pages'],axis=1,inplace = True)

print(data.head())

#checking null values
print(data.isnull().sum())

# fill missing value
data["authors"] = data["authors"].fillna("unknown")
data["categories"] = data["categories"].fillna("unknown")
data["average_rating"] = data["average_rating"].fillna(0)
data["ratings_count"] = data["ratings_count"].fillna(0)
data['description']=data['description'].fillna("no description")

#again check null values
print(data.isnull().sum())

#put the title to lower
data['title'] = data['title'].str.lower()
#save data
data.to_csv("new_data.csv")

#to show the data on the home screen
#use only title and category
r = data[['title','categories']]
h=r.head(20)

#save data
h.to_csv("list of books.csv")

