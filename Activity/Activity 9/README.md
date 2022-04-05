## Activity 9 

Please create a FUSE-base file system with the following features.

- read-only file system

- contains 2 files: subject and instructors
    
    ```
    cat subject
    ```
    show
    ```
    subject contains:
    2110313 - Operating System
    2021/2
    ```
    and
    ```
    cat instructors
    ```
    show 
    ```
    instructors contains:
    0 : Instructors of 2110313 - 2021/2
    1:   Krerk Piromsopa, Ph.D.
    2:  Veera Muangsin, Ph. D.
    3:  Thongchai Rojkangsadan 
    ```

- Please submit 2 files. The first file is a screenshot demonstrated your work. The second file is the source code.

## Preparation 

I do this activity in [Github Codespaces](https://github.com/features/codespaces) since I don't have Linux.

First, install [libfuse-dev](https://packages.ubuntu.com/search?keywords=libfuse-dev) in your Codespaces

```zsh
sudo apt-get install libfuse-dev
```

Then, install [fuse-python](https://github.com/libfuse/python-fuse) to manage your virtual filesystem.

```
pip install fuse-python
```

Make sure you use python 3+

Happy coding!

