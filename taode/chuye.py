import pandas as pd

df = pd.read_csv(
    "de4.txt",
    encoding="utf-8"
)

df.to_excel(
    "de4.xlsx",
    index=False
)