if has('vim_starting')
  set nocompatible
  set runtimepath+=~/vimfiles/bundle/neobundle.vim/
endif

filetype off
filetype plugin off
filetype indent off
  
" =============================================================================
" NeoBundle
" =============================================================================
call neobundle#begin(expand('~/vimfiles/bundle/'))
NeoBundleFetch 'Shougo/neobundle.vim'
NeoBundle 'Shougo/unite.vim'
NeoBundle 'Shougo/neomru.vim'
NeoBundle 'Shougo/neocomplete.vim'
NeoBundle 'Shougo/neosnippet.vim'
NeoBundle 'Shougo/neosnippet-snippets'
NeoBundle 'itchyny/lightline.vim'
NeoBundle 'thinca/vim-quickrun'
NeoBundle 'osyo-manga/shabadou.vim'
NeoBundle 'thinca/vim-ref'
NeoBundle 'w0ng/vim-hybrid' 
NeoBundle 'Shougo/unite-outline'
NeoBundle 'sgur/unite-everything'
NeoBundle 'scrooloose/syntastic'
NeoBundle 'koron/codic-vim'
NeoBundle 'rhysd/unite-codic.vim'
NeoBundle 'nathanaelkane/vim-indent-guides'
call neobundle#end()

NeoBundleCheck


" =============================================================================
" settings
" =============================================================================
set number
set ts=4 sw=4 sts=4
set incsearch
set smartindent
set nobackup
set noswapfile
set wildmode=longest:full
set list
set listchars=tab:^\_,trail:~,extends:.
set autochdir
set tags=tags;
set noundofile
set laststatus=2
set cmdheight=2
set showcmd
set backspace=indent,eol,start 

autocmd QuickFixCmdPost *grep* cwindow
autocmd guienter * set transparency=245

" colorscheme molokai
colorscheme hybrid

if $TERM == "xterm"
  set shell=bash
endif


" =============================================================================
" keymapping
" =============================================================================
inoremap jj <esc>
nnoremap <C-l> <C-w>>
nnoremap <C-h> <C-w><
nnoremap <C-j> <C-w>+
nnoremap <C-k> <C-w>-
nnoremap J 5j
nnoremap K 5k
vnoremap J 5j
vnoremap K 5k
nnoremap <ESC><ESC> :nohlsearch<CR>
nnoremap t <C-t>
nnoremap ] gt
nnoremap [ gT


" =============================================================================
" neocomplete
" =============================================================================
let g:acp_enableAtStartup = 0
let g:neocomplete#enable_at_startup = 1
let g:neocomplete#enable_smart_case = 1
let g:neocomplete#sources#syntax#min_keyword_length = 3
let g:neocomplete#lock_buffer_name_pattern = '\*ku\*'

" Define keyword.
if !exists('g:neocomplete#keyword_patterns')
    let g:neocomplete#keyword_patterns = {}
endif
let g:neocomplete#keyword_patterns['default'] = '\h\w*'

inoremap <expr><C-g>     neocomplete#undo_completion()
inoremap <expr><C-l>     neocomplete#complete_common_string()

inoremap <silent> <CR> <C-r>=<SID>my_cr_function()<CR>
function! s:my_cr_function()
  return pumvisible() ? neocomplete#close_popup() : "\<CR>"
endfunction
inoremap <expr><TAB>  pumvisible() ? "\<C-n>" : "\<TAB>"
inoremap <expr><C-h> neocomplete#smart_close_popup()."\<C-h>"
inoremap <expr><BS> neocomplete#smart_close_popup()."\<C-h>"

autocmd FileType css setlocal omnifunc=csscomplete#CompleteCSS
autocmd FileType html,markdown setlocal omnifunc=htmlcomplete#CompleteTags
autocmd FileType javascript setlocal omnifunc=javascriptcomplete#CompleteJS
autocmd FileType python setlocal omnifunc=pythoncomplete#Complete
autocmd FileType xml setlocal omnifunc=xmlcomplete#CompleteTags

if !exists('g:neocomplete#sources#omni#input_patterns')
  let g:neocomplete#sources#omni#input_patterns = {}
endif
let g:neocomplete#sources#omni#input_patterns.cpp = '[^.[:digit:] *\t]\%(\.\|->\)\|\h\w*::'
let g:neocomplete#sources#omni#input_patterns.ruby = '[^. *\t]\.\h\w*\|\h\w*::'


" =============================================================================
" neosnippet
" =============================================================================
let g:neosnippet#enable_snipmate_compatibility = 1
let g:neosnippet#snippets_directory='C:\vim\snippets\'

imap <expr><C-Space> neosnippet#expandable() ? "\<Plug>(neosnippet_expand_or_jump)" : pumvisible() ? "\<C-n>" : "\<C-Space>"
imap <expr><Space>   neosnippet#jumpable()   ? "\<Plug>(neosnippet_expand_or_jump)" : "\<Space>"

" For snippet_complete marker.
if has('conceal')
  set conceallevel=2 concealcursor=i
endif


" =============================================================================
" quickrun
" =============================================================================
call quickrun#module#register(shabadou#make_quickrun_hook_anim(
\	"santi_pinch",
\	['＼(・ω・＼)　SAN値！', '　(／・ω・)／ピンチ！',],
\	24,
\), 1)

let g:quickrun_config = {
\   "_" : {
\       "runner" : "vimproc",
\       "runner/vimproc/updatetime" : 40,
\       "hook/santi_pinch/enable" : 1,
\       "hook/santi_pinch/wait" : 30,
\       "outputter/error/error" : "quickfix",
\       "outputter/error/success" : "buffer",
\       "outputter" : "error",
\       "hook/quickfix_replate_tempname_to_bufnr/enable_exit" : 1,
\       "hook/quickfix_replate_tempname_to_bufnr/priority_exit" : -10,
\   },
\   'cpp/vc': {
\   'command': 'cl',
\   'exec': ['%c %o %s /nologo /Fo%s:p:r.obj /Fe%s:p:r.exe',
\            '%s:p:r.exe %a'],
\   'tempfile': '%{tempname()}.cpp',
\   'hook/sweep/files': ['%S:p:r.exe', '%S:p:r.obj'],
\ },
\  "msbuild" : {
\    "command": "search_and_msbuild.bat",
\    "exec": "%c %o %s:p:r",
\    "cmdopt": "",
\  },
\}

let g:quickrun_config.cpp = { "type": "cpp/vc" }

nnoremap <expr><silent> <C-c> quickrun#is_running() ? quickrun#sweep_sessions() : "\<C-c>"


" =============================================================================
" ref 
" =============================================================================
let g:ref_refe_encoding = "UTF-8"
" let g:ref_no_default_key_mappings = 1
nmap <silent> <unique> + <Plug>(ref-keyword)
vmap <silent> <unique> + <Plug>(ref-keyword)

let g:ref_source_webdict_sites = {
\   'wikipedia_ja': { 'url': 'http://ja.wikipedia.org/wiki/%s' },
\ }

" 出力に対するフィルタ。最初の数行を削除している。
function! g:ref_source_webdict_sites.wikipedia_ja.filter(output)
  return join(split(a:output, "\n")[18 :], "\n")
endfunction

" =============================================================================
" unite
" =============================================================================
let g:unite_enable_start_insert = 1
let g:unite_source_history_yank_enable = 1
nnoremap <silent> <C-Space> :<C-u>Unite everything/async -buffer-name=everything<CR>
nnoremap <silent> <C-f> :<C-u>Unite buffer file_mru file -buffer-name=searcher<CR>
nnoremap <silent> ,y :<C-u>Unite history/yank -buffer-name=history/yank<CR>

au FileType unite nnoremap <silent> <buffer> <expr> <C-l> unite#do_action('vsplit')
au FileType unite inoremap <silent> <buffer> <expr> <C-l> unite#do_action('vsplit')
au FileType unite nnoremap <silent> <buffer> <expr> <C-o> unite#do_action('tabopen')
au FileType unite inoremap <silent> <buffer> <expr> <C-o> unite#do_action('tabopen')
au FileType unite nnoremap <silent> <buffer> <ESC><ESC> :q<CR>
au FileType unite inoremap <silent> <buffer> <ESC><ESC> <ESC>:q<CR>

nnoremap <silent> ,g :<C-u>Unite grep:. -buffer-name=search-buffer<CR>
if executable('pt')
  let g:unite_source_grep_command = 'pt'
  let g:unite_source_grep_default_opts = '--nogroup --nocolor'
  let g:unite_source_grep_recursive_opt = ''
  let g:unite_source_grep_encoding = 'utf-8'
endif


" =============================================================================
" syntasitc
" =============================================================================
let g:syntastic_ruby_checkers = ['rubocop']


" =============================================================================
" codic
" =============================================================================
inoremap <silent> <C-Z>  <C-R>=<SID>codic_complete()<CR>
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
" indent-guide 
" =============================================================================
let g:indent_guides_enable_on_vim_startup = 1


filetype on
filetype plugin on
filetype indent on
syntax on
