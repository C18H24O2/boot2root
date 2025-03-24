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
    john
    qemu
    python312
  ] ++ (with pkgs.python312Packages; [
      paramiko
    ]);
}
