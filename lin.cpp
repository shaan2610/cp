*******************************************************LINUX*******************************************************
date -r file //shows when the file is last modified
date +%d%(m/b/B)%(y/Y) / %a-week day
tee //store output in multiple files
grep -l //shows the name of the matched file
in ls 9th column in file name
ls -t //sort according to time modified
ls -d //shows dir info
ls -F //   / is at the last of directory
ls -1 //file names in long format
lstart //time at which computer was started
ps -p PID -o etime //elapsed time
wc -m/c //char
wc -L //length of longest line
df --total //total 
df 3rd field -> used 4th -> available
df -T file //file type
uname -r //release date of kernal
unmae -o //os
unmae -v //version
unmae -s //linux
sort -k 2n //sorting about 2nd column
sort -c //check whether the file is already sorted or not
sort -u //sort and remove dublicates
sort -M //Month
spell -on//chk spelling and n for lines
ispell //to replace a word which is not in dictionary to another word
du -Sh //size of file
split -d/*numerical*/-l[num] -b [size] -n[num]/*no of files*/ filename #suffix change
cmp -i [1st file]:[2nd file] //skip
cmp -n [num] //numbers of byte to be compared
top //list all the system processes
who -q //list the login name of all users
shutdown -r [time] //reboot after time
cut -d "delimitor" -f [num],[num] /*fields to show*/ file --output-delimiter="new"
tr -s 'char' / -d char


Asssgn 1 -> 8,
Asssgn 2 -> 10,
Asssgn 4 -> 3,4,

