set nu              " 显示行号
syntax on           " 语法高亮
set nobackup "覆盖文件时不备份
set autoindent "自动缩进
"set noautoindent
set ruler           " 显示标尺
set cursorline              " 突出显示当前行
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}
set laststatus=2    " 启动显示状态行(1),总是显示状态行(2)
set nocompatible  "去掉讨厌的有关vi一致性模式，避免以前版本的一些bug和局限  
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
set fileencodings=ucs-bom,utf-8,cp936
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
""实用设置
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"自动保存
set autowrite
set magic                   " 设置魔术
""set guioptions-=T           " 隐藏工具栏
""set guioptions-=m           " 隐藏菜单栏
""set statusline=\ %<%F[%1*%M%*%n%R%H]%=\ %y\ %0(%{&fileformat}\ %{&encoding}\ %c:%l/%L%)\
" 设置在状态行显示的信息
set foldcolumn=0
set foldmethod=indent 
set foldlevel=10000
set foldenable              " 开始折叠
" 不要使用vi的键盘模式，而是vim自己的
set nocompatible
" 语法高亮
set syntax=on
" 在处理未保存或只读文件的时候，弹出确认
set confirm
" Tab键的宽度
set tabstop=4
" 统一缩进为4
set softtabstop=4
set shiftwidth=4
" 历史记录数
set history=1000
"搜索忽略大小写
set ignorecase
"搜索逐字符高亮
set hlsearch
set incsearch
"行内替换
set gdefault
"编码设置
set enc=utf-8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
"语言设置
set langmenu=zh_CN.UTF-8
set helplang=cn
" 我的状态行显示的内容（包括文件类型和解码）
"set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [POS=%l,%v][%p%%]\ %{strftime(\"%d/%m/%y\ -\ %H:%M\")}
"set statusline=[%F]%y%r%m%*%=[Line:%l/%L,Column:%c][%p%%]
" 总是显示状态行
""set laststatus=2
" 命令行（在状态行下）的高度，默认为1，这里是2
set cmdheight=1
" 侦测文件类型
filetype on
" 载入文件类型插件
filetype plugin on
" 为特定文件类型载入相关缩进文件
filetype indent on
" 保存全局变量
set viminfo+=!
" 带有如下符号的单词不要被换行分割
set iskeyword+=_,$,@,%,#,-
" 字符间插入的像素行数目
set linespace=0
" 增强模式中的命令行自动完成操作
set wildmenu
" 使回格键（backspace）正常处理indent, eol, start等
set backspace=2
" 允许backspace和光标键跨越行边界
set whichwrap+=<,>,h,l
" 通过使用: commands命令，告诉我们文件的哪一行被改变过
set report=0
" 在被分割的窗口间显示空白，便于阅读
set fillchars=vert:\ ,stl:\ ,stlnc:\
" 高亮显示匹配的括号
set showmatch
" 匹配括号高亮的时间（单位是十分之一秒）
set matchtime=1
" 光标移动到buffer的顶部和底部时保持3行距离
set scrolloff=3
" 高亮显示普通txt文件（需要txt.vim脚本）
au BufRead,BufNewFile *  setfiletype txt
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"其他东东
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"Tony"
hi def LogF_color ctermfg=white guifg=white ctermbg=red guibg=red
hi def LogE_color ctermfg=darkred guifg=darkred
hi def LogW_color ctermfg=brown guifg=brown
hi def LogI_color ctermfg=blue guifg=blue
hi def LogD_color ctermfg=green guifg=green
hi def LogV_color ctermfg=gray guifg=gray
syn match LogF  '\(^F[ ]\+\|^F\/\|^[0-9:\.\- ]*[ ]\+F[ ]\+\|^[0-9:\.\- ]*[ ]\+F\/\).*'
syn match LogE  '\(^E[ ]\+\|^E\/\|^[0-9:\.\- ]*[ ]\+E[ ]\+\|^[0-9:\.\- ]*[ ]\+E\/\).*'
syn match LogW  '\(^W[ ]\+\|^W\/\|^[0-9:\.\- ]*[ ]\+W[ ]\+\|^[0-9:\.\- ]*[ ]\+W\/\).*'
syn match LogI  '\(^I[ ]\+\|^I\/\|^[0-9:\.\- ]*[ ]\+I[ ]\+\|^[0-9:\.\- ]*[ ]\+I\/\).*'
syn match LogD  '\(^D[ ]\+\|^D\/\|^[0-9:\.\- ]*[ ]\+D[ ]\+\|^[0-9:\.\- ]*[ ]\+D\/\).*'
syn match LogV  '\(^V[ ]\+\|^V\/\|^[0-9:\.\- ]*[ ]\+V[ ]\+\|^[0-9:\.\- ]*[ ]\+V\/\).*'
hi def link LogF LogF_color
hi def link LogE LogE_color
hi def link LogW LogW_color
hi def link LogI LogI_color
hi def link LogD LogD_color
hi def link LogV LogV_color
"End of Tony"
""set statusline=[%F]%y%r%m%*%=[Line:%l/%L,Column:%c][%p%%]
