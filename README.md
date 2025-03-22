# XQPwdLineEdit
Password line edit using Qt Widgets with show/hide toggle

Embedded icons got from <a href="https://www.flaticon.com/authors/bankume" target="_blank">FlatIcon - bankume</a>, but you can set your icons either.

### 📌 Adding XQPwdLineEdit as a Git Submodule

1. Navigate to your project directory:

```sh
cd /path/to/your/project
```

2. Add the repository as a submodule:

```sh
git submodule add https://github.com/xaprier/XQPwdLineEdit your_lib_directory/XQPwdLineEdit
```

3. Initialize and update the submodule:

```sh
git submodule update --init --recursive
```

4. Linking XQPwdLineEdit with CMake
```cmake
add_subdirectory(your_lib_directory/XQPwdLineEdit)
target_link_libraries(${PROJECT_NAME} PRIVATE XQPwdLineEdit)
```

### 📚 Dependencies

- CMake(Building project)
- Qt(Widgets)
- Git(Just for cloning repository)

### ✨ Contributors

<a href="https://github.com/xaprier/XQPwdLineEdit/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=xaprier/XQPwdLineEdit" />
</a>