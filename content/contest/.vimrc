set background=dark
set number
syntax on
set mouse=a
set backspace=indent,eol,start
set autoindent
set hlsearch

ca Hash w !cpp -dD -P -fpreprocessed \| tr -d '[:space:]' \
 \| md5sum \| cut -c-6
