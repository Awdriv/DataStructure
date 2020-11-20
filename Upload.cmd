@echo off

title 上传至 Github

git add *
git commit -m "%DATE% %TIME%"
git push -u origin master
