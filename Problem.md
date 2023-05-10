# CSIE4004_HW4
## 題目說明
小明是個勤奮向上的好學生，在上課時都會乖乖地準備好課本。可是全新版的原文書實在是太貴了，小明沒有足夠的錢向系學會一起團購書籍，於是他決定拿著自己的購書清單去二手書店，看有沒有機會撿到便宜的二手書。

到了書店後，書店的老闆給了小明一張店裡的目錄，告訴他書名都按照字母順序排列整齊，且後面標示出書本的價格。請幫小明找到每一本書的價格，並紀錄各書本的價格，和統計花費的總金額。


## Input Format
輸入總共有兩行

第一行為小明購書清單的檔案名稱

第二行為書店目錄的檔案名稱

購書清單的檔案內容範例`list01.txt`如下：
```
Calculus
art
Datastructures&Algorithms
Naruto
Calculus
```
由於檔案內容的大小不固定，所以請讀到EOF為止。
每行只有由英文單字(含大小寫)的一本書，不含空白。

書店目錄的檔案總共`n+1`行。

第一行為一正整數`n`，接著`n`行為書本的名稱 + 空白 + 書本的價格(正整數)。
目錄的檔案內容範例`store01.txt`如下：
```
6
Alphabet 150
Accounting 600
Calculus 550
Chemistry 400
Datastructures&Algorithms 380
Economics 450
```

## Output Format
輸出購書的總金額

## Output File Format
請將清單的書本名稱依照ASCII Code的順序由小到大排好後，再輸出至檔名為`noteXX.txt`的檔案中。例：`list01.txt`就輸入到`note01.txt`

假設購書清單有`k`本書，則寫入的檔案總共有`k`行，，每一行輸出形式為`已排序之書本名稱 書本價格`。

注意
1. 有可能會出現店裡沒有賣小明想要的書的情況，此時價格需寫入`None`
1. 清單有可能出現重複的書籍，表示小明想要多買，請不要省略
1. 書店保證不會有同樣書名卻價格不同的書籍

## Sample Input
```
list01.txt
store01.txt
```
## Sample Output

```
1480
```

## Sample Output File note01.txt
```
Calculus 550
Calculus 550
Datastructures&Algorithms 380
Naruto None
art None
```

## Hint
清單的書本數k的限制為  `0 < k < 500`
書名長度會小於`64`
* subtask 0 (10%) ：sample input
* subtask 1-3 (30%) ：清單不需排序，且沒有`None`的情況
* subtask 4-6 (30%) ：清單不需排序，會出現`None`
* subtask 7-8 (30%) ：無限制