case "$OSTYPE" in
  linux*)
    free -t -h > ex1.txt ;;
  darwin*)
    vmstat > ex1.txt ;;
  msys*)
    systeminfo | find "Physical Memory" > "ex1.txt"
    systeminfo | find "Virtual Memory" >> "ex1.txt" ;;
  cygwin*)
    systeminfo | find "Physical Memory" > "ex1.txt"
    systeminfo | find "Virtual Memory" >> "ex1.txt" ;;
esac

