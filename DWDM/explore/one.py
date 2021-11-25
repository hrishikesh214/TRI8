import numpy as np
import pandas as pd

sl1 = pd.Series(np.array([10,20,30,40,50]))
sl2 = pd.Series(np.array(['a', 'b', 'c']))
sl2.index = [3,5,6]

sl3 =pd.Series( {
    'a': [1,2,3],
    'b': [4,5,6],
})

countries = {
    'India': 'Japan',
    'UK' : 'Singapore',
    'USA': 'China',
}

sl4 = pd.Series(countries)



print(sl1)