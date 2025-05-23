{
  pkgs ? import <nixpkgs> {
    nixpkgs.config.permittedInsecurePackages = [
      "python-2.7.18.8"
    ];
  },
}:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    net-snmp
    sshpass
    nikto
    feroxbuster
    wireshark
    nmap
    ghidra-bin
    john
    qemu
    python311
    p7zip
    python2 # I cast 200 days build-time!!!!
  ] ++ (with pkgs.python311Packages; [
      # tkinter
      turtle
      paramiko
    ]);
}
