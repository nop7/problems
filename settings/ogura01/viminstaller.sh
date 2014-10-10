sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install git make curl -y

# vim
# apt-get build-dep vim -y

sudo apt-get install mercurial gettext libncurses5-dev libacl1-dev libgpm-dev -y
sudo apt-get install libperl-dev python-dev python3-dev ruby-dev -y
sudo apt-get install lua5.2 liblua5.2-dev -y
sudo apt-get install luajit libluajit-5.1 -y

hg clone https://vim.googlecode.com/hg/ vimbuild
cd vimbuild \
  && hg pull \
  && hg update \
  && ./configure --with-features=huge --enable-gui=gnome2 \
                 --enable-perlinterp --enable-pythoninterp \
                 --enable-python3interp --enable-rubyinterp \
                 --enable-luainterp --with-luajit \
                 --enable-fail-if-missing \
                 --enable-xim --enable-multibyte --enable-fontset \
                 --prefix=/usr/local \
   && sudo make \
   && sudo make install

cd ..
sudo rm -r vimbuild

sudo apt-get autoremove
