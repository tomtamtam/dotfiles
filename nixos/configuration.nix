{ config, pkgs, ... }:

{
  imports =
    [ # Include the results of the hardware scan.
      ./hardware-configuration.nix
    ];

  # Bootloader.
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;

  # Use latest kernel.
  boot.kernelPackages = pkgs.linuxPackages_latest;

  networking.hostName = "nixos"; # Define your hostname.
  # networking.wireless.enable = true;  # Enables wireless support via wpa_supplicant.

  # Configure network proxy if necessary
  # networking.proxy.default = "http://user:password@proxy:port/";
  # networking.proxy.noProxy = "127.0.0.1,localhost,internal.domain";

  # Enable networking
  networking.networkmanager.enable = true;

 # Set your time zone.
  time.timeZone = "Europe/Berlin";

  # Select internationalisation properties.
  i18n.defaultLocale = "en_US.UTF-8";

  i18n.extraLocaleSettings = {
    LC_ADDRESS = "de_DE.UTF-8";
    LC_IDENTIFICATION = "de_DE.UTF-8";
    LC_MEASUREMENT = "de_DE.UTF-8";
    LC_MONETARY = "de_DE.UTF-8";
    LC_NAME = "de_DE.UTF-8";
    LC_NUMERIC = "de_DE.UTF-8";
    LC_PAPER = "de_DE.UTF-8";
    LC_TELEPHONE = "de_DE.UTF-8";
    LC_TIME = "de_DE.UTF-8";
  };

  # Configure keymap in X11
  services.xserver.enable = false;

  # Configure console keymap
  console.keyMap = "de";

users.users.tom = {
  isNormalUser = true;
  description = "tom";
  extraGroups = [ "networkmanager" "wheel" "video" ];
  packages = with pkgs; [];
};

programs.zsh.enable = true;
users.users.tom.shell = pkgs.zsh;

services.udisks2.enable = true;
services.gvfs.enable = true;

# Auto-login on tty1
# services.getty.autologinUser = "tom";

# Add Hyprland auto-start to your shell config
programs.zsh.interactiveShellInit = ''
  if [[ -z $DISPLAY ]] && [[ $(tty) == /dev/tty1 ]]; then
    exec Hyprland
  fi
'';

# Allow unfree packages
  nixpkgs.config.allowUnfree = true;

hardware.graphics = {
  enable = true;
  enable32Bit = true;
};


  # List packages installed in system profile. To search, run:
  # $ nix search wget
  environment.systemPackages = with pkgs; [
    neovim
    wget
    gnumake
    cmake
    gcc
    python3
    firefox
    kitty
    wl-clipboard
    hyprpaper
    discord
    spotify
    ripgrep
    nodejs_24
    obsidian
    git
    btop
    brightnessctl
    tree-sitter
    clang
    clang-tools
    waybar
    cargo
    nautilus
    gtk4
    nwg-look
    veracrypt
    swaynotificationcenter
    hyprpaper
    rofi
    neofetch
    zsh
    xdg-user-dirs
    virtualbox
    mpc
    alsa-utils
    light
    acpi
    pavucontrol
    libnotify
    hyprpicker
    hyprshot
    gruvbox-gtk-theme
    pywal
    adwaita-icon-theme
    hicolor-icon-theme
    papirus-icon-theme
    networkmanagerapplet
    bluez
    bluez-tools
    blueman
    pulseaudio
    filius
    steam
    heroic
    libreoffice
    udisks
  ];
  programs.hyprland.enable = true;

  fonts.packages = with pkgs; [
    noto-fonts
    noto-fonts-cjk-sans
    noto-fonts-color-emoji
    liberation_ttf
    fira-code
    fira-code-symbols
    mplus-outline-fonts.githubRelease
    dina-font
    proggyfonts
    nerd-fonts.fira-code
];


  
  # Some programs need SUID wrappers, can be configured further or are
  # started in user sessions.
  # programs.mtr.enable = true;
  # programs.gnupg.agent = {
  #   enable = true;
  #   enableSSHSupport = true;
  # };

  # List services that you want to enable:

  # Enable the OpenSSH daemon.
  # services.openssh.enable = true;

  # Open ports in the firewall.
  # networking.firewall.allowedTCPPorts = [ ... ];
  # networking.firewall.allowedUDPPorts = [ ... ];
  # Or disable the firewall altogether.
  # networking.firewall.enable = false;

  # This value determines the NixOS release from which the default
  # settings for stateful data, like file locations and database versions
  # on your system were taken. It‘s perfectly fine and recommended to leave
  # this value at the release version of the first install of this system.
  # Before changing this value read the documentation for this option
  # (e.g. man configuration.nix or on https://nixos.org/nixos/options.html).
  system.stateVersion = "25.11"; # Did you read the comment?

}
