import pandas as pd

df = pd.read_csv(
    "de3.txt",
    encoding="utf-8"
)

df.to_excel(
    "outputy.xlsx",
    index=False
)