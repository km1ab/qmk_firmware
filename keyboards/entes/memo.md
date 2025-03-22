# ハマったメモ

## ロータリーエンコーダー
ロータリーエンコーダー(EC12E2420801)かなりハマったのでメモを残す。

原因が、EC12、qmkバージョン、MCU(RP2040)、接触不良、GPIO指定間違えなのか、いろいろと悩んだ。どれも見当違い。

以下の注意書きを見落としただけだった。

- https://tech.alpsalpine.com/j/products/detail/EC12E2420801/

の「ご使用上の注意」
のフィルタ回路例にある、「C端子」↓↓↓↓

**GNDにつながっています。**

ただの配線不足！！

推奨としては、フィルタ回路を組むべきとのこと。
フィルタ回路はなくても動作したが、GND接続を見落としていたのは致命的だった。

# 参考サイト
- キーマップ関連
    - https://github.com/qmk/qmk_firmware/blob/master/quantum/quantum_keycodes.h
    - https://qiita.com/nemolize/items/7f3b9d65d02cf31a5169
- XIAO RP2040
    - https://www.switch-science.com/products/7634?srsltid=AfmBOoraMIKzfAfWzGMfhmFyVvpUwXy6bibaG5vwSvk0ArWDwB1sRrfQ