# მონაცემების წაკითხვა
import pandas as pd
data = pd.read_csv('Quiz 1.csv')
data.head()

# გავაერთიანოთ ორი სვეტი, გადავიტანოთ ცალკე (ახალ) სვეტში
data ['Electronic Advertising'] = (data['TV']+data['Radio'])/2
data.head()

# წავშალოთ გაერთიანებული სვეტები
data.drop(['TV', 'Radio'], axis=1, inplace=True)
data.head()

# X და y განვაცალკევოთ ერთმანეთისგან
y = data['Electronic Advertising'].values
X = data.drop('Electronic Advertising', axis=1).values

# Sklearn დახმარებით შემოვიტანოთ Train და Test ფუნქციები
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=1)

# ავაგოთ LinearRegression და გამოვთვალოთ Score, რომ შევაფასოთ რამდენად კარგი მოდელია
from sklearn.linear_model import LinearRegression
model = LinearRegression()
model.fit(X_train, y_train)
model.score(X_test, y_test)

!pip install lime yellowbrick

# შემოვიტანოთ Lime ბიბლიოთეკა
import lime
import lime.lime_tabular
import matplotlib.pyplot as plt
explainer =lime.lime_tabular.LimeTabularExplainer(X_train, feature_names=columns, class_names=['Electronic Advertising'], mode='regression', verbose=1)
i = 5
exp = explainer.explain_instance(X_test[i],model.predict,num_features=2)
exp.as_pyplot_figure()
plt.show()
exp.show_in_notebook(show_table=True)
exp.as_list()

# მეორე ქვიზი

import pandas as pd
data = pd.read_csv("Football.csv")
data.head()

data = data[["age", "height_cm", "weight_kg", "league_rank", "overall", "potential", "international_reputation", "mentality_vision"]]
data.head()

data = data.head(200)
from sklearn.manifold import TSNE
mycluster1 = TSNE(n_components=2, learning_rate='auto', init='random', perplexity=40)
X1 = mycluster1.fit_transform(data)
X1

import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

from sklearn.cluster import KMeans
mycluster1 = KMeans(n_clusters=3)
mycluster1.fit(X1)
y = mycluster1.predict(X1)
y

plt.scatter(X1[:,0],X1[:,1],c=y)
plt.scatter(mycluster1.cluster_centers_[:,0],mycluster1.cluster_centers_[:,1],s=80,c="black")
plt.show()