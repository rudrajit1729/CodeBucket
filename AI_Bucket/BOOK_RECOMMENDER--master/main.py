import pandas as pd
from flask import Flask, render_template, request

app = Flask(__name__)
#print(__name__)

def recm(b):
    data = pd.read_csv("new_data.csv")
    f = b.lower() 
    if f not in data['title'].unique():
        return('This book is not in our database.\nPlease check if you spelled it correct.')
    else:
        i = data[data['title']==f]
        y= i.index[0]
        g = i['categories']
        c=g[y]
        r=data[data['categories']==c]
        w = r[r['title']  == f].index
        k = r.drop(w)
        s = k.sort_values(by='average_rating',ascending=False)

        name = []
        description = []
        author = []
        rating = []
        for o in s.index:  
            name.append(s["title"][o])
    
            description.append(s['description'][o])
        
            author.append(s["authors"][o])
            rating.append(s["average_rating"][o])

            print("  ")

        if len(name) >=10:
            topname = name[1:11]
            topdes = description[1:11]
            topaut = author[1:11]
            toprat = rating[1:11]
        else :
            topname = name
            topdes = description
            topaut = author
            toprat = rating
    return topname , topdes , topaut , toprat
        
    


@app.route("/")
def home():
    lst = pd.read_csv("list of books.csv")
    d = list(lst['title'])
    r = render_template('home.html' , list_book = d)
    return r

@app.route("/recomend")
def recommend():
    b = request.args.get('book')
    s = recm(b)
    b = b.title()
    if type(s)==type('string'):
        return render_template('recommend.html',book = b, s = s, t = 's')

    else:
        return render_template('recommend.html',book = b, s = s ,t='l')





if __name__ == '__main__':
    app.run(debug=True)

