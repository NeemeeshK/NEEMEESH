import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import  accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
data=pd.read_csv("diabetes.csv")
x=data.iloc[:,:-1]
y=data.iloc[:,-1]
X_train,X_test,y_train,y_test=train_test_split(x,y,test_size=25,random_state=0)
classifier=RandomForestClassifier(n_estimators=6,criterion='entropy',random_state=0)
classifier.fit(X_train, y_train)
y_pred=classifier.predict(X_test)
acc_randomforest=round(accuracy_score(y_pred,y_test))*100
classifier=LogisticRegression(solver="lbfgs",max_iter=1000)
classifier.fit(X_train, y_train)
y_pred=classifier.predict(X_test)
acc_logisticreg=round(accuracy_score(y_pred,y_test))*100
classifier=KNeighborsClassifier(n_neighbors=6)
classifier.fit(X_train, y_train)
y_pred=classifier.predict(X_test)
acc_knn=round(accuracy_score(y_pred,y_test))*100
print(acc_randomforest)
print(acc_logisticreg)
print(acc_knn)
print(type(data))