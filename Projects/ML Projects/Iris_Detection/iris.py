import pandas 
import numpy
import seaborn as sns      
import sklearn      
import matplotlib.pyplot as plt
# get_ipython().run_line_magic('matplotlib', 'inline')
import pandas as pd  
iris=pd.read_csv(r"C:\Users\nimis_r\OneDrive\Desktop\iris_csv.csv")  
iris.head(10)
print(len(iris['class']))
for col in iris.columns:
    print(col)
print(iris.groupby('class').size()) 
plt.figure(figsize=(15,10))    
plt.subplot(2,2,1)    
sns.boxplot(x='class',y='sepallength',data=iris)    
plt.subplot(2,2,2)    
sns.boxplot(x='class',y='sepalwidth',data=iris)    
plt.subplot(2,2,3)    
sns.boxplot(x='class',y='petallength',data=iris)    
plt.subplot(2,2,4)    
sns.boxplot(x='class',y='petalwidth',data=iris)    
iris.isnull().values.any()
iris.info()
from sklearn.model_selection import train_test_split
array = iris.values    
X = array[:,0:4]    
Y = array[:,4]      
x_train,x_test, y_train, y_test = train_test_split(X, Y, test_size=0.3,random_state=0)    
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score
svc = SVC(max_iter=1000,gamma='auto')
svc.fit(x_train, y_train)
y_pred = svc.predict(x_test)
acc_svc = round(accuracy_score(y_pred,y_test) , 2)*100
print("Accuracy :" ,acc_svc)
from sklearn.tree import DecisionTreeClassifier
decisiontree = DecisionTreeClassifier( random_state=0)
decisiontree.fit(x_train, y_train)
y_pred = decisiontree.predict(x_test)
acc_decisiontree = round(accuracy_score(y_pred, y_test) , 2)*100
print("Accuracy :" ,acc_decisiontree)
from sklearn.linear_model import LogisticRegression
logreg=LogisticRegression(max_iter=1000)
logreg.fit(x_train, y_train)
y_pred = logreg.predict(x_test)
acc_logreg = round(accuracy_score(y_pred, y_test) , 2)*100
print("Accuracy : ",acc_logreg)