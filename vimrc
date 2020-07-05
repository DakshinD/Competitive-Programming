source $VIMRUNTIME/vimrc_example.vim

au GUIEnter * simalt ~x
set nocompatible
set tabstop=4
set shiftwidth=4
set expandtab
set autoindent
set smartindent
set ruler
set clipboard=unnamed
set showcmd
set incsearch
set number
set relativenumber
set cino+=L0
set t_Co=256
set belloff=all

let g:conoline_use_colorscheme_default_normal=1
let g:conoline_use_colorscheme_default_insert=1
let g:airline_theme='base16_monokai'
let g:sublimemonokai_term_italic = 1
colorscheme sublimemonokai

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
nmap <C-c> gcc

if has("autocmd")
	augroup templates
		autocmd BufNewFile *.cpp exe "0r D:\\cp\\templates\\".input("Template Name (cf - codeforces | usaco - usaco | cses - cses): ").".cpp" |
			\ set syntax=cpp |
			\ set filetype=cpp
	augroup END
endif


autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -ggdb3 -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -o2 -Wno-narrowing -fvisibility=hidden -fmax-errors=2 -std=c++17 % -o %:r<CR>
autocmd filetype cpp nnoremap <F10> :!%:r<CR>
 
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
