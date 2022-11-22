# PCとVS Codeを新しくセットアップするときの各種設定

## 目次
- [PC Software設定(Windows)](#pc-software関連設定windows)
- [PC プログラミング系Software(Windows)](#pc-プログラミング系softwarewindows)
- [WSL and LaTeX設定](#wsl-and-latex設定)
- [Github SSH と GPG設定](#github-ssh-と-gpg設定)

<br>

## PC Software関連設定(Windows)
- [Google Chrome](https://www.google.com/intl/ja_jp/chrome/)
- [Office365](https://www.microsoft.com/ja-jp/microsoft-365/buy/compare-all-microsoft-365-products-b)
- [Adobe Acrobat Reader](https://get.adobe.com/jp/reader/)
- [7zip](https://sevenzip.osdn.jp/)
- [Slack](https://slack.com/intl/ja-jp/downloads/windows)
- [PowerToys](https://apps.microsoft.com/store/detail/XP89DCGQ3K6VLD)
- [SylphyHorn](https://www.microsoft.com/store/productId/9NBLGGH58T01)

<br>

## PC プログラミング系Software(Windows)
- [Visual Studio](https://visualstudio.microsoft.com/ja/vs/community/)
- [Visual Studio Code](https://azure.microsoft.com/ja-jp/products/visual-studio-code/)
- [Github Desktop](https://desktop.github.com/)
- [Anaconda](https://www.anaconda.com/products/distribution)
- [Ruby](https://rubyinstaller.org/)
- [TDM GCC](https://jmeubank.github.io/tdm-gcc/download/)
- [Git for Windows](https://gitforwindows.org/)

<br>

## WSL and LaTeX設定

### TeX Environments

| Subject | Text | 
| --- | --- |
| OS | Windows10 + WSL2 |
| Editor | Visual Studio Code |
| Compiler | TeX Live | 

### Compile Command
1. Texファイルを開く
2. **ctrl + alt + v** (PDFをプレビューしようとするが開けない)
3. **ctrl + s** (保存時にコンパイルされる，↑のコマンドを先に実行しないとコンパイルされない謎)
4. **ctrl + alt + v** (今度はコンパイルされているので開ける)
5. 以降は **ctrl + s** を押す度に自動でコンパイルされる<br>
	VS Codeを起動するたびにこの過程が必要です(良い方法があれば教えてください)

## Installation(?) -- How to make LaTeX Environment on your PC.

**保存するたびに自動コンパイルされる環境をローカルで作る** <br>

参考文献 : [VScodeでLaTeXの環境を整える](https://www.takameron.info/post/vscode_latex/ "hoge")


- 管理者権限でPowerShellを起動 <br>
	- ```wsl --install``` <br>
	(WSL2のインストール)

- Microsoft Storeを起動
	- Ubuntu22.04 を検索 & インストール

- Ubuntu22.04を起動
	- 以下のコマンドで必要なパッケージをインストール <br>
	  Fullだと7GBぐらいあるので(分かるのであれば)必要なtexlive関連パッケージだけで大丈夫です．
		```
		sudo apt update
		sudo apt upgrade
		sudo apt install texlive-full
		``` 
	- ~/.latexmkrc 作成して以下をコピペ
		```
		#!/usr/bin/env perl
		$latex            = 'uplatex -shell-escape -kanji=utf8 -synctex=1 -halt-on-error -interaction=nonstopmode -file-line-error %O %S';
		$latex_silent     = 'uplatex -shell-escape -kanji=utf8 -synctex=1 -halt-on-error -interaction=batchmode %O %S';
		$bibtex           = 'pbibtex %O %S';
		$biber            = 'biber --bblencoding=utf8 -u -U --output_safechars';
		$dvipdf           = 'dvipdfmx %O -o %D %S';
		$makeindex        = 'mendex %O -o %D %S';
		$max_repeat       = 5;
		$pdf_mode         = 3;
		$pvc_view_file_via_temporary = 0;
		$ENV{TZ} = 'Asia/Tokyo';
		$ENV{OPENTYPEFONTS} = '/usr/share/fonts//:';
		$ENV{TTFONTS} = '/usr/share/fonts//:';
		
		# clean up
		$clean_full_ext = "%R.synctex.gz"
		```

- VS Codeを起動
	- Remote WSLをインストール (ms-vscode-remote.remote-wsl)
	- WSLに接続
	- LaTeX Workshopをインストール (James-Yu.latex-workshop)
	- settings.jsonはこのリポジトリにあるので設定不要

<br>

## Github SSH と GPG設定
1. OneDrive → .ssh を C:/Users/okabe/.ssh にコピー
2. 	```
	git config --global user.name "tokabe333"
	git config --global user.email "tokabe333@gmail.com"
	```
	config等は.sshに含まれているため記述不要

3. ---------- ここからGPG ---------- <br>
	- [GPG for Windows](https://gpg4win.org/get-gpg4win.html)のダウンロード & インストール  
	<br> もしくは <br>
	- 環境変数に ```C:\Program Files\Git\usr\bin``` を追加
4. gpg鍵の登録 & IDの確認 <br>
	OneDrive/_PC_Setting/.gnupg に移動
	```
	gpg --import seckey.gpg
	gpg -k
	``` 
5. 	```
	git config --global gpg.program <my gpg.exe path>
	git config --global commit.gpgsign true
	git config --global user.signingkey "<my key id>"
	```
	my gpg.exe path には C:/Program Files/Git/usr/bin/gpg がデフォルトでは入るはず
6. CUIで鍵を使えるように(UNIX系) .bashrcに以下を記述 <br>
	```
	export GPG_TTY=$(tty)
	```
