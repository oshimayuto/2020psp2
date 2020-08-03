# 課題4 レポート

bb35319014　大嶌　優仁

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
14~23.引数宣言
26~32.サンプルからデータを取得する
36.ファイルを開く
37~41.ファイルが正常に開かれなかった時プログラムを終了する
43.ファイルを開く
44~48.ファイルが正常に開かれなかった時プログラムを終了する
51~64.取得したデータがしっかりあるとき、MaleかFemaleかを判断してnを更新する
67~80.input_idとman[i].idが一致するときそれぞれを出力する。違った場合はスキップする
83~86.nが更新されてないときNo dataと出力する
88~98.ファイルからこれ以上データが読み取れないときファイルを閉じる

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

input the filename of sample height:c:\Users\bb35319014\Desktop\2020psp2\sample\heights.csv
input the filename of sample ID:c:\Users\bb35319014\Desktop\2020psp2\sample\IDs.csv
which ID's data do you want? : 45313002

ID : 45313002
Gender ; Female
Heights : 183.870

## 修正履歴

