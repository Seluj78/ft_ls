echo "\033[35m FT_LS Testeur par jlasne\n\n"

echo "\033[33mMake du project\033[0m"
make
echo "\n\033[34mTests basics :\n"
echo "\033[33m./ft_ls\033[0m"
./ft_ls
echo "\n\033[33m./ft_ls ~/\033[0m"
./ft_ls ~/
echo "\n\033[33m./ft_ls -l\033[0m"
./ft_ls -l
echo "\n\033[33m./ft_ls -l ~/\033[0m"
./ft_ls -l ~/
echo "\033[33m./ft_lsi -a\033[0m"
./ft_ls -a
echo "\n\033[33m./ft_ls -a ~/\033[0m"
./ft_ls -a ~/
echo "\n\033[33m./ft_ls -la\033[0m"
./ft_ls -la
echo "\n\033[33m./ft_ls -la ~/\033[0m"
./ft_ls -la ~/
echo "\n\033[33m./ft_ls -lRa\033[0m"
./ft_ls -lRa
echo "\n\033[33m./ft_ls -a ~/\033[0m"
./ft_ls -a ~/
echo "\n\033[33m./ft_ls ~/ -a\033[0m"
./ft_ls ~/ -a
echo "\n\033[33m./ft_ls --\033[0m"
./ft_ls --
echo "\n\033[33m./ft_ls -a --\033[0m"
./ft_ls -a --
echo "\n\033[33m./ft_ls -a -- -a\033[0m"
./ft_ls -a -- -a
echo "\n\033[33m./ft_ls -r\033[0m"
./ft_ls -r
echo "\n\033[33m./ft_ls -t\033[0m"
./ft_ls -t
echo "\n\033[33m./ft_ls THISFILEDOESNTEXISTS\033[0m"
./ft_ls THISFILEDOESNTEXISTS
echo "\n\033[33m./ft_ls THOSE FILES NEITHER\033[0m"
./ft_ls THOSE FILES NEITHER
echo "\n\033[33m./ft_ls -l THISFILEDOESNTEXISTS\033[0m"
./ft_ls -l THISFILEDOESNTEXISTS
echo "\n\033[33m./ft_ls -l THOSE FILES NEITHER\033[0m"
./ft_ls -l THOSE FILES NEITHER


#mkdir unacessible
#chmod 000 unacessible
#./ft_ls unacessible
#./ft_ls -l unacessible
#./ft_ls -lR unacessible
#chmod 777 unacessible
#rm -rf unacessible

#./ft_ls srcs Makefile

#./ft_ls ""

#./ft_ls "-a"

#./ft_ls "- a"

#./ft_ls -a -- srcs
echo "\n\033[33m\033[0m"
