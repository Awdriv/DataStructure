@echo off

title eScape Sync

git add --all
git commit -m "%DATE% %TIME%"
git push -u origin master

timeout /T 5
