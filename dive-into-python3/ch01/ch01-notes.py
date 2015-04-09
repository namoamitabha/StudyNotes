[angelo@centos dive-into-python3]$ python3
Python 3.3.2 (default, May 10 2014, 10:24:41) 
[GCC 4.8.2 20140120 (Red Hat 4.8.2-16)] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> exit()
[angelo@centos dive-into-python3]$ ls
ch01  humansize.py  humansize.py~
[angelo@centos dive-into-python3]$ python3 humansize.py
1.0TB
931.3GiB
[angelo@centos dive-into-python3]$ git status
# On branch master
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#	./
nothing added to commit but untracked files present (use "git add" to track)
[angelo@centos dive-into-python3]$ ls
ch01  humansize.py  humansize.py~
[angelo@centos dive-into-python3]$ python3
Python 3.3.2 (default, May 10 2014, 10:24:41) 
[GCC 4.8.2 20140120 (Red Hat 4.8.2-16)] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> from humansize import approximate_size
>>> approximate_size(4000, a_kilobyte_is_1024_bytes=False)
'4.0KB'
>>> approximate_size(size=4000, a_kilobyte_is_1024_bytes=False)
'4.0KB'
>>> approximate_size(a_kilobyte_is_1024_bytes=False, size=4000)
'4.0KB'
>>> approximate_size(a_kilobyte_is_1024_bytes=False, 4000)
  File "<stdin>", line 1
SyntaxError: non-keyword arg after keyword arg
>>> approximate_size(size=4000, False)
  File "<stdin>", line 1
SyntaxError: non-keyword arg after keyword arg
>>> approximate_size(4000, False)
'4.0KB'
>>> import sys
>>> sys.path
['', '/usr/lib64/python33.zip', '/usr/lib64/python3.3', '/usr/lib64/python3.3/plat-linux', '/usr/lib64/python3.3/lib-dynload', '/usr/lib64/python3.3/site-packages', '/usr/lib/python3.3/site-packages']
>>> sys
<module 'sys' (built-in)>
>>> pwd
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'pwd' is not defined
>>> sys.path.insert(0, '/home/angelo/git-root/study-notes/dive-into-python3
  File "<stdin>", line 1
    sys.path.insert(0, '/home/angelo/git-root/study-notes/dive-into-python3
                                                                          ^
SyntaxError: EOL while scanning string literal
>>> sys.path.insert(0, '/home/angelo/git-root/study-notes/dive-into-python3')
>>> sys.path
['/home/angelo/git-root/study-notes/dive-into-python3', '', '/usr/lib64/python33.zip', '/usr/lib64/python3.3', '/usr/lib64/python3.3/plat-linux', '/usr/lib64/python3.3/lib-dynload', '/usr/lib64/python3.3/site-packages', '/usr/lib/python3.3/site-packages']
>>> 
>>> import humansize
>>> print(humansize.approximate_size(4096, True))
4.0KiB
>>> print(humansize.approximate_size.__doc__)
Convert a file size to human-readable form.
    Keyword arguments:
    size -- file size in bytes
    a_kilobyte_is_1024_bytes -- if True (default), buse multiples of 1024
                                if False, use multiples of 1000

    Returns: string

