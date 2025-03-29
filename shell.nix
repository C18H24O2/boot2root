{
  pkgs ? import <nixpkgs> {},
}:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    net-snmp
    sshpass
    feroxbuster
    wireshark
    nmap
    ghidra-bin
    john
    qemu
    python311
  ] ++ (with pkgs.python311Packages; [
      # tkinter
      turtle
      paramiko
    ]);
}
