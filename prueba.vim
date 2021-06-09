let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Documents/programacion/githubRepositories/DataStructuresAndAlgos
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +27 ~/Documents/programacion/githubRepositories/DataStructuresAndAlgos/burbuja.cpp
badd +0 term://~/Documents/programacion/githubRepositories/DataStructuresAndAlgos//15512:C:/Windows/system32/cmd.exe
argglobal
%argdel
edit ~/Documents/programacion/githubRepositories/DataStructuresAndAlgos/burbuja.cpp
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd w
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 26 + 27) / 55)
exe '2resize ' . ((&lines * 26 + 27) / 55)
argglobal
balt ~/Documents/programacion/githubRepositories/DataStructuresAndAlgos/burbuja.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let &fdl = &fdl
let s:l = 27 - ((12 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 27
normal! 0
wincmd w
argglobal
if bufexists("term://~/Documents/programacion/githubRepositories/DataStructuresAndAlgos//15512:C:/Windows/system32/cmd.exe") | buffer term://~/Documents/programacion/githubRepositories/DataStructuresAndAlgos//15512:C:/Windows/system32/cmd.exe | else | edit term://~/Documents/programacion/githubRepositories/DataStructuresAndAlgos//15512:C:/Windows/system32/cmd.exe | endif
if &buftype ==# 'terminal'
  silent file term://~/Documents/programacion/githubRepositories/DataStructuresAndAlgos//15512:C:/Windows/system32/cmd.exe
endif
balt ~/Documents/programacion/githubRepositories/DataStructuresAndAlgos/burbuja.cpp
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 4 - ((3 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 4
normal! 080|
wincmd w
exe '1resize ' . ((&lines * 26 + 27) / 55)
exe '2resize ' . ((&lines * 26 + 27) / 55)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0&& getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=filnxtToOF
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
