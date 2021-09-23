import pandas as pd
from nltk.stem.snowball import SnowballStemmer
from nltk.stem import WordNetLemmatizer
from nltk.corpus import stopwords
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics import  accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.svm import LinearSVC
tfidf=TfidfVectorizer()
data=pd.read_csv("spam1.csv", encoding="Windows-1252")
data['spam']=data['v1'].map({'spam':1,'ham':0}).astype(int)
def tokenizer(text):
    return text.split()
data['text']=data['text'].apply(tokenizer)
porter=SnowballStemmer("english",ignore_stopwords=False)
def stem_it(text):
    return [porter.stem(word) for word in text]
data['text']=data['text'].apply(stem_it)
lemmatizer=WordNetLemmatizer()
def lemmit_it(text):
    return [lemmatizer.lemmatize(word,pos="a") for word in text]
def stop_it(text):
    stop_words=stopwords.words("english")
    review=[word for word in text if not word in stop_words]
    return review
data['text']=data['text'].apply(lemmit_it)
data['text']=data['text'].apply(stop_it)
data['text']=data['text'].apply(' '.join)
y=data.spam.values
x=tfidf.fit_transform(data['text'])
X_train,X_text,y_train,y_text=train_test_split(x,y,random_state=1,test_size=0.2,shuffle=True)
clf=LogisticRegression()
clf.fit(X_train,y_train)
y_pred=clf.predict(X_text)
clf_accuracy=accuracy_score(y_pred,y_text)*100
linear_svc=LinearSVC(random_state=0)
linear_svc.fit(X_train,y_train)
y_pred=linear_svc.predict(X_text)
svc_accuracy=accuracy_score(y_pred,y_text)*100
print("ACCURACY", clf_accuracy)
print("ACCURACY", svc_accuracy)
print(data.head(5))