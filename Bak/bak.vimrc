syntax on

imap jj <ESC>
imap <A-/> <C-n>
imap {{ {<ESC>o}<ESC>O

set nu
set tabstop=4
set autoindent
set nobackup
set noswapfile
set enc=utf-8
set fenc=utf-8
set fencs=ucs-bom,utf-8,cp936,gb18030,big5,euc-jp,euc-kr,latin1

map <F2> :call SetTitle()<CR> 
func SetTitle() 
	let l = 0 
	let l = l + 1 | call setline(l,'#include <bits/stdc++.h>') 
	let l = l + 1 | call setline(l,'using namespace std;') 
	let l = l + 1 | call setline(l,'') 
	let l = l + 1 | call setline(l,'int main()') 
	let l = l + 1 | call setline(l,'{') 
	" let l = l + 1 | call setline(l,'    //freopen("in.txt","r",stdin);') 
	" let l = l + 1 | call setline(l,'    //freopen("out.txt","w",stdout);') 
	let l = l + 1 | call setline(l,'    ') 
	let l = l + 1 | call setline(l,'    return 0;') 
	let l = l + 1 | call setline(l,'}') 
	let l = l + 1 | call setline(l,'//Last modified :  '.strftime("%Y-%m-%d %H:%M CST"))
endfunc  
