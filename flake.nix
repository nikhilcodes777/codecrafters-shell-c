{
  description = "Codecrafters C Shell";

  inputs = {
    nixpkgs.url = "nixpkgs";
    systems.url = "github:nix-systems/x86_64-linux";
    flake-utils = {
      url = "github:numtide/flake-utils";
      inputs.systems.follows = "systems";
    };
  };

  outputs =
    {
      # self,
      nixpkgs,
      flake-utils,
      ...
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        pname = "c-shell"; # package name
        version = "0.0.1";
        src = ./.;
        buildInputs = with pkgs; [
        ];
        nativeBuildInputs = with pkgs; [
          clang-tools
          cmake
          readline
          vcpkg
          gnumake
        ];
      in
      {
        devShells.default = pkgs.mkShell {
          inherit buildInputs nativeBuildInputs;
          VCPKG_ROOT = "${pkgs.vcpkg}/share/vcpkg";

        };

        packages.default = pkgs.stdenv.mkDerivation {
          inherit
            buildInputs
            nativeBuildInputs
            pname
            version
            src
            ;
        };
      }
    );
}
