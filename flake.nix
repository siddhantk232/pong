{
  description = "A very basic flake";

  outputs = { self, nixpkgs }:
  let
    system = "x86_64-linux";
    pkgs = import nixpkgs { inherit system; };
  in
  {
    devShells.${system}.default = pkgs.mkShell {
        name = "pong-shell";
        buildInputs = with pkgs; [
          raylib
          pkg-config
        ];
      };
  };
}

