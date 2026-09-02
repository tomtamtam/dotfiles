# Dotfiles

my dotfiles for hyprland, hyprpaper, neovim

## Sync Tool
I also wrote a sync tool in c++.
The idea is to have the config in the repo dir in e.g. ~/ and automaticly sync it with ~/.config, so you can edit and commit in the repo.
### How to use
create a json config file like this:
``` json
{
    "directories": [
        {"origin": "/home/tom/dotfiles/hypr", "dest": "/home/tom/.config/hypr"},
        {"origin": "some_other_repo", "dest": "/home/tom/.config/some_other_app"}
    ],
    "files": {
        {"origin": "some_file.conf", "dest": "/home/tom/.config/some_file.conf"}
    }
}
```

> [!IMPORTANT]
> do not use ~/ in the config

thene call the sync app with the config as the **only** arg:

```bash
./build/sync /home/tom/dotfiles/sync.json
```

### Build


```bash
git clone https://github.com/tomtamtam/dotfiles.git
cd dotfiles/sync
mkdir build && cd build
cmake ..
make
```

