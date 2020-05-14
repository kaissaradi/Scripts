import pandas as pd
import os
from matplotlib import pyplot as plt
import seaborn as sns


file_path = "/home/admin/Documents/Python/Data-Vis/ign_scores.csv"
df = pd.read_csv(file_path,index_col="Platform")

plt.figure(figsize=(10,7),dpi=100)
sns.heatmap(data=df)
plt.xticks(rotation=40, ha="right")


plt.title("Average Score by Genre and Platform")

plt.show()


