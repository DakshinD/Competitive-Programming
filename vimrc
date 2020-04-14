" Vim with all enhancements
source $VIMRUNTIME/vimrc_example.vim
set tabstop=4
set nocompatible
set shiftwidth=4
set expandtab
set autoindent
set smartindent
set ruler
set clipboard=unnamed
set showcmd
set incsearch
"set shellslash
set number
set relativenumber
set cino+=L0
set t_Co=256   " This is may or may not needed.

let g:conoline_use_colorscheme_default_normal=1
let g:conoline_use_colorscheme_default_insert=1
let g:airline_theme='base16_gruvbox_dark_hard'

set background=dark
colorscheme gruvbox
set gfn=Fixedsys:h17
syntax on
filetype indent on

call plug#begin()
Plug 'scrooloose/nerdtree'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'airblade/vim-gitgutter'
Plug 'tpope/vim-commentary'
Plug 'tpope/vim-surround'
Plug 'yggdroot/indentline'
Plug 'mattn/emmet-vim'
Plug 'w0rp/ale'
Plug 'miyakogi/conoline.vim'
call plug#end()
 
"keybindings for { completion, "jk" for escape, ctrl-a to select all
inoremap {<CR>  {<CR>}<Esc>O
inoremap {}     {}
imap jk         <Esc>
map <C-a> <esc>ggVG<CR>
set belloff=all
 
autocmd BufNewFile *.cpp 0r C:\Users\Dakshin Devanand\Competitive Programming\template.cpp"autofills new C++ files with your template
autocmd filetype cpp nnoremap <F9> :w <bar> !g++.exe -static -DONLINE_JUDGE -lm -s -x c++ -Wl,--stack=268435456 -Wall -Wextra -O2 -std=c++11 -D__USE_MINGW_ANSI_STDIO=0 -o %:r.exe %:r.cpp <CR> "F9 to compile
autocmd filetype cpp nnoremap <F10> :!%:r<CR> "F10 to run
 
"tip: use a folder for competitive programming, with subfolders for each contest and a subfolder for your library.
"then, to insert library code, do :r ../Library/FILENAME.cpp

" Use the internal diff if available.
" Otherwise use the special 'diffexpr' for Windows.
if &diffopt !~# 'internal'
  set diffexpr=MyDiff()
endif
function MyDiff()
  let opt = '-a --binary '
  if &diffopt =~ 'icase' | let opt = opt . '-i ' | endif
  if &diffopt =~ 'iwhite' | let opt = opt . '-b ' | endif
  let arg1 = v:fname_in
  if arg1 =~ ' ' | let arg1 = '"' . arg1 . '"' | endif
  let arg1 = substitute(arg1, '!', '\!', 'g')
  let arg2 = v:fname_new
  if arg2 =~ ' ' | let arg2 = '"' . arg2 . '"' | endif
  let arg2 = substitute(arg2, '!', '\!', 'g')
  let arg3 = v:fname_out
  if arg3 =~ ' ' | let arg3 = '"' . arg3 . '"' | endif
  let arg3 = substitute(arg3, '!', '\!', 'g')
  if $VIMRUNTIME =~ ' '
    if &sh =~ '\<cmd'
      if empty(&shellxquote)
        let l:shxq_sav = ''
        set shellxquote&
      endif
      let cmd = '"' . $VIMRUNTIME . '\diff"'
    else
      let cmd = substitute($VIMRUNTIME, ' ', '" ', '') . '\diff"'
    endif
  else
    let cmd = $VIMRUNTIME . '\diff'
  endif
  let cmd = substitute(cmd, '!', '\!', 'g')
  silent execute '!' . cmd . ' ' . opt . arg1 . ' ' . arg2 . ' > ' . arg3
  if exists('l:shxq_sav')
    let &shellxquote=l:shxq_sav
  endif
endfunction

