@echo off

title GitHub Sync

git add *
git commit -m "%DATE% %TIME%"
git push -u origin master
