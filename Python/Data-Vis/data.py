#import libraries and read data file
import pandas as pd
import os
from matplotlib import pyplot as plt
import seaborn as sns
df = pd.read_csv("iris.csv")
print(df.head())