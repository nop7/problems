set encoding=utf-8
scriptencoding utf-8
set fileencoding=utf-8
set fileencodings=utf-8,cp932,iso-2022-jp,sjis,euc-jp
set fileformat=unix
set fileformats=unix,dos,mac

if has('vim_starting')
  if has('win32')
    set runtimepath+=~/vimfiles/bundle/neobundle.vim/
  else
    set runtimepath+=~/.vim/bundle/neobundle.vim/
  endif
endif

" =============================================================================
" NeoBundle
" =============================================================================
if has('win32')
  call neobundle#begin(expand('~/vimfiles/bundle/'))
else
  call neobundle#begin(expand('~/.vim/bundle/'))
endif

NeoBundleFetch 'Shougo/neobundle.vim'

if !has('win32')
  NeoBundle 'Shougo/vimproc', {
\   'build' : {
\       'cygwin'  : 'make -f make_cygwin.mak',
\       'mac'     : 'make -f make_mac.mak',
\       'unix'    : 'make -f make_unix.mak',
\   },
\  }
endif
NeoBundle 'w0ng/vim-hybrid'         " カラースキーム
NeoBundle 'Shougo/unite.vim'        " 検索インタフェース
NeoBundle 'Shougo/neomru.vim'       " 履歴
NeoBundle 'Shougo/neocomplete.vim'  " 補完
NeoBundle 'Shougo/neosnippet.vim'   " スニペット補完
NeoBundle 'Shougo/neosnippet-snippets' " スニペット集
NeoBundle 'Shougo/unite-outline'    " コード中のクラスの概要
NeoBundle 'itchyny/lightline.vim'   " 綺麗なステータスライン
NeoBundle 'thinca/vim-ref'          " クイックリファレンス閲覧
NeoBundle 'thinca/vim-quickrun'     " バッファのコードを実行
NeoBundle 'osyo-manga/shabadou.vim' " QuickRunの拡張
NeoBundle 'osyo-manga/vim-watchdogs' " 静的コード解析(非同期)
NeoBundle 'sgur/unite-everything'   " デスクトップ検索
NeoBundle 'dannyob/quickfixstatus'  " quickfixをコマンドウィンドウに表示
NeoBundle 'KazuakiM/vim-qfsigns'    " quickfixをsign領域に表示
NeoBundle 'koron/codic-vim'         " 英和辞書(補完にも使う)
NeoBundle 'rhysd/unite-codic.vim'   " uniteで英和辞書を使う
NeoBundle 'tpope/vim-rails'         " rails
NeoBundle 'kannokanno/previm'       " プレビュー
NeoBundle 'tyru/open-browser.vim'   " ブラウザオープン
NeoBundle 'tpope/vim-surround'      " テキストオブジェクト
" NeoBundle 'scrooloose/syntastic'    " 静的コード解析
" NeoBundle 'ekalinin/Dockerfile.vim' " docker
call neobundle#end()

filetype plugin indent on
NeoBundleCheck

" =============================================================================
" settings
" =============================================================================
set number              " 行数表示
set ts=4 sw=4 sts=4     " 基本インデント
set incsearch           " インクリメントサーチ
set smartindent         " スマートインデント
set nobackup            " バックアップ無し
set noswapfile          " スワップ無し
set noundofile          " undoファイル無し
set autochdir           " 開いたファイルのディレクトリに移動
set tags=tags;          " タグの設定
set laststatus=2        " ステータス行を2行にする
set cmdheight=2         " コマンド行は1行に
set showcmd             " 常にステータス行を表示する
set clipboard=unnamed   " クリップボード共有
set showmatch           " 対応する括弧の表示
set hlsearch            " 検索結果のハイライト
set history=100         " ヒストリの最大
set shellslash          " Windowsで/
set list                " 不可視文字描画
set listchars=tab:^\_,trail:~,extends:.
set backspace=indent,eol,start  " インデントを消せるようにする
set wildmenu
set wildmode=list,longest:full
set cursorline
hi clear CursorLine

" grepしたらquickfixを表示
autocmd QuickFixCmdPost *grep* cwindow
" 透明度の設定
autocmd guienter * set transparency=245
" vimfiles/ftplugin/ruby.vim が反映されなかったらココ！
" autocmd FileType ruby setlocal expandtab ts=2 sts=2 sw=2 autoindent

if $TERM == "xterm"
  set shell=bash
endif

set t_Co=256

" カラースキーム
let g:hybrid_use_Xresources = 1
colorscheme hybrid

" =============================================================================
" keymapping
" =============================================================================
" エスケープ
inoremap jj <ESC>
" <ESC>連打でハイライトを消す
nnoremap <ESC><ESC> :nohlsearch<CR>
" ウィンドウ幅の調整
nnoremap <C-l> <C-w>>
nnoremap <C-h> <C-w><
nnoremap <C-j> <C-w>+
nnoremap <C-k> <C-w>-
" いっぱい移動する
nnoremap J 5j
nnoremap K 5k
vnoremap J 5j
vnoremap K 5k
" タブの移動
nnoremap } gt
nnoremap { gT
" タグ関係
nnoremap t <C-t>

" =============================================================================
" neocomplete
" =============================================================================
let g:acp_enableAtStartup = 0
let g:neocomplete#enable_at_startup = 1
let g:neocomplete#enable_smart_case = 1
let g:neocomplete#sources#syntax#min_keyword_length = 3
let g:neocomplete#lock_buffer_name_pattern = '\*ku\*'

if !exists('g:neocomplete#keyword_patterns')
  let g:neocomplete#keyword_patterns = {}
endif
let g:neocomplete#keyword_patterns['default'] = '\h\w*'

inoremap <silent> <CR> <C-r>=<SID>my_cr_function()<CR>
function! s:my_cr_function()
  return pumvisible() ? neocomplete#close_popup() : "\<CR>"
endfunction
inoremap <expr><TAB>  pumvisible() ? "\<C-n>" : "\<TAB>"

autocmd FileType css setlocal omnifunc=csscomplete#CompleteCSS
autocmd FileType html,markdown setlocal omnifunc=htmlcomplete#CompleteTags
autocmd FileType javascript setlocal omnifunc=javascriptcomplete#CompleteJS
autocmd FileType python setlocal omnifunc=pythoncomplete#Complete
autocmd FileType xml setlocal omnifunc=xmlcomplete#CompleteTags
autocmd FileType ruby set omnifunc=rubycomplete#Complete

" ドットやアローで補完リストを表示する
if !exists('g:neocomplete#force_omni_input_patterns')
  let g:neocomplete#force_omni_input_patterns = {}
endif
let g:neocomplete#force_omni_input_patterns.ruby = '[^. *\t]\.\w*\|\h\w*::'
" let g:neocomplete#force_omni_input_patterns.cpp  = '[^.[:digit:] *\t]\%(\.\|->\)\|\h\w*::'

if !exists('g:neocomplete#sources#omni#input_patterns')
  let g:neocomplete#sources#omni#input_patterns = {}
endif
" let g:neocomplete#sources#omni#input_patterns.cpp = '[^.[:digit:] *\t]\%(\.\|->\)\|\h\w*::'
" let g:neocomplete#sources#omni#input_patterns.ruby = '[^. *\t]\.\h\w*\|\h\w*::'

" <C-Space>でオムニ補完 VisualStudioに合わせる
imap <Nul> <C-x><C-o>
imap <C-Space> <C-X><C-O>

" =============================================================================
" neosnippet
" =============================================================================
let g:neosnippet#enable_snipmate_compatibility = 1
let g:neosnippet#snippets_directory='~/dotfiles/snippets/'

" <C-Space>でスニペットを展開する
imap <expr><C-Space> neosnippet#expandable() ? "\<Plug>(neosnippet_expand_or_jump)" : pumvisible() ? "\<C-n>" : "\<C-Space>"
imap <expr><Space>   neosnippet#jumpable()   ? "\<Plug>(neosnippet_expand_or_jump)" : "\<Space>"

" For snippet_complete marker.
if has('conceal')
  set conceallevel=2 concealcursor=i
endif

" =============================================================================
" quickrun
" =============================================================================
" 実行中は SAN値! ピンチ! する
function! s:iconv_list(l)
  if has('win32')
    return map(a:l,"iconv(v:val,'cp932','utf-8')")
  endif
  return a:l
endfunction

call quickrun#module#register(shabadou#make_quickrun_hook_anim(
\	'santi_pinch',
\	s:iconv_list(['＼(・ω・＼)　SAN値！', '　(／・ω・)／ピンチ！',]),
\	6,
\), 1)

" エラーならquickfix, 成功ならバッファに表示
let g:quickrun_config = {
\  '_' : {
\    'runner': 'vimproc',
\    'runner/vimproc/updatetime': 40,
\    'hook/santi_pinch/enable': 1,
\    'hook/time/enable': 1,
\    'outputter': 'multi:buffer:quickfix',
\    'hook/quickfix_replate_tempname_to_bufnr/enable_exit': 1,
\    'hook/quickfix_replate_tempname_to_bufnr/priority_exit': -10,
\    'hook/close_quickfix/enable_success': 1,
\    'hook/close_quickfix/enable_hook_loaded': 1,
\  },
\  'cpp/vc': {
\    'exec': ['cl.bat %o %S /Fo%S:P:R.obj /Fe%S:P:R.exe > nul',
\             '%S:P:R.exe %a'],
\    'tempfile': '%{tempname()}.cpp',
\    'hook/sweep/files': ['%S:P:R.exe', '%S:P:R.obj'],
\    'hook/output_encode/encoding': 'cp932'
\  },
\  'watchdogs_checker/vc' : {
\    'command'   : 'cl.bat',
\    'exec'      : '%c /Zs %o %s:p ',
\    'hook/output_encode/encoding': 'cp932'
\	},
\  'watchdogs_checker/_' : {
\    'outputter/quickfix/open_cmd' : '',
\    'hook/qfsigns_update/enable_exit':   1,
\    'hook/qfsigns_update/priority_exit': 3,
\  },
\  'ruby/watchdogs_checker' : { 'type' : 'watchdogs_checker/rubocop' },
\  'cpp/watchdogs_checker'  : { 'type' : 'watchdogs_checker/vc' },
\}

" VC++をデフォルトにしておく
if has('win32')
  let g:quickrun_config.cpp = { 'type': 'cpp/vc' }
endif

" <C-c>でQuickRunの強制終了
nnoremap <expr><silent> <C-c> quickrun#is_running() ? quickrun#sweep_sessions() : '\<C-c>'

" =============================================================================
" watchdogs
" =============================================================================
call watchdogs#setup(g:quickrun_config)

let g:watchdogs_check_BufWritePost_enable = 1

let g:qfsigns#Config = {'id': '5050', 'name': 'QFError',}
execute 'sign define '.get(g:qfsigns#Config,'name').' texthl=Error text=>>'

" =============================================================================
" ref
" =============================================================================
let g:ref_refe_encoding = "UTF-8"
" + でカーソル下の単語のリファレンスを開く
nmap <silent> + <Plug>(ref-keyword)
vmap <silent> + <Plug>(ref-keyword)

" =============================================================================
" unite
" =============================================================================
let g:unite_enable_start_insert = 1         " 最初からinsertモードにしておく
let g:unite_source_history_yank_enable = 1  " ヤンク履歴とか使えるようにする
let g:unite_source_history_yank_limit = 100 " 履歴の最大を設定

" , にショートカットを割り振っておく
" Everythingを起動している必要あり、加えて別途es.exeをDLしてパスを通す
nnoremap <silent> ,a  :<C-u>Unite everything/async -buffer-name=everything<CR>
" 最近開いたファイルとかその他諸々(かなり高速)
nnoremap <silent> ,f :<C-u>Unite buffer file_mru file -buffer-name=searcher<CR>
" ヤンク(コピー履歴)
nnoremap <silent> ,y :<C-u>Unite history/yank -buffer-name=history/yank<CR>
" grep結果, :Unite grep:(パス)
nnoremap <silent> ,g :<C-u>Unite grep:. -buffer-name=search-buffer<CR>
" outline結果, :Unite outline
nnoremap <silent> ,r :<C-u>Unite grep:. -buffer-name=search-buffer<CR>
" ファイル
nnoremap <silent> ,z :<C-u>Unite file -buffer-name=filer<CR>

" <C-l>でウィンドウ分割して開く, <C-o>でタブで開く
au FileType unite nnoremap <silent> <buffer> <expr> <C-l> unite#do_action('vsplit')
au FileType unite inoremap <silent> <buffer> <expr> <C-l> unite#do_action('vsplit')
au FileType unite nnoremap <silent> <buffer> <expr> <C-o> unite#do_action('tabopen')
au FileType unite inoremap <silent> <buffer> <expr> <C-o> unite#do_action('tabopen')
au FileType unite nnoremap <silent> <buffer> <ESC><ESC> :q<CR>
au FileType unite inoremap <silent> <buffer> <ESC><ESC> <ESC>:q<CR>

" grepはthe platium searcherを使う（速い！） (必須) pt.exe
if executable('pt')
  let g:unite_source_grep_command = 'pt'
  let g:unite_source_grep_default_opts = '--nogroup --nocolor'
  let g:unite_source_grep_recursive_opt = ''
  let g:unite_source_grep_encoding = 'utf-8'
endif

set grepprg=pt\ --nogroup

" =============================================================================
" codic
" =============================================================================
inoremap <silent> <C-o>  <C-R>=<SID>codic_complete()<CR>
function! s:codic_complete()
  let line = getline('.')
  let start = match(line, '\k\+$')
  let cand = s:codic_candidates(line[start :])
  call complete(start +1, cand)
  return ''
endfunction
function! s:codic_candidates(arglead)
  let cand = codic#search(a:arglead, 30)
  " error
  if type(cand) == type(0)
    return []
  endif
  " english -> english terms
  if a:arglead =~# '^\w\+$'
    return map(cand, '{"word": v:val["label"], "menu": join(map(copy(v:val["values"]), "v:val.word"), ",")}')
  endif
  " japanese -> english terms
  return s:reverse_candidates(cand)
endfunction
function! s:reverse_candidates(cand)
  let _ = []
  for c in a:cand
    for v in c.values
      call add(_, {"word": v.word, "menu": !empty(v.desc) ? v.desc : c.label })
    endfor
  endfor
  return _
endfunction

" =============================================================================
" previm
" =============================================================================
augroup PrevimSettings
  autocmd!
  autocmd BufNewFile,BufRead *.{md,mdwn,mkd,mkdn,mark*} set filetype=markdown
augroup END

" Previm
let g:previm_open_cmd = ''
nnoremap [previm] <Nop>
nnoremap <silent> <F7> :<C-u>PrevimOpen<CR>
nnoremap <silent> <F5> :call previm#refresh()<CR>

" =============================================================================
" paste mode
" =============================================================================
" 貼り付け時に無駄にインデントするのを防ぐ
if &term =~ "xterm"
  let &t_ti .= "\e[?2004h"
  let &t_te .= "\e[?2004l"
  let &pastetoggle = "\e[201~"

  function XTermPasteBegin(ret)
    set paste
    return a:ret
  endfunction

  noremap <special> <expr> <Esc>[200~ XTermPasteBegin("0i")
  inoremap <special> <expr> <Esc>[200~ XTermPasteBegin("")
  cnoremap <special> <Esc>[200~ <nop>
  cnoremap <special> <Esc>[201~ <nop>
endif

" =============================================================================
filetype on
filetype plugin on
filetype indent on
syntax on
