#!/bin/sh
set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
cd $SCRIPT_DIR

ROOT=$SCRIPT_DIR/../..
echo "Spine Runtimes path: $ROOT"
echo "Copying assets to runtimes..."
echo ""

echo "spine-haxe"
rm "$ROOT/spine-haxe/example/assets/"*
cp -f ../coin/export/coin-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../coin/export/coin-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../coin/export/coin.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../coin/export/coin.png "$ROOT/spine-haxe/example/assets/"

cp -f ../goblins/export/goblins-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../goblins/export/goblins-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../goblins/export/goblins.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../goblins/export/goblins.png "$ROOT/spine-haxe/example/assets/"

cp -f ../dragon/export/dragon-ess.json "$ROOT/spine-haxe/example/assets/"
cp -f ../dragon/export/dragon-ess.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../dragon/export/dragon.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../dragon/export/dragon*.png "$ROOT/spine-haxe/example/assets/"

cp -f ../raptor/export/raptor-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../raptor/export/raptor-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../raptor/export/raptor.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../raptor/export/raptor.png "$ROOT/spine-haxe/example/assets/"

cp -f ../spineboy/export/spineboy-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../spineboy/export/spineboy-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../spineboy/export/spineboy.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../spineboy/export/spineboy.png "$ROOT/spine-haxe/example/assets/"
cp -f ../spineboy/export/spineboy.png "$ROOT/spine-haxe/example/assets/"

cp -f ../tank/export/tank-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../tank/export/tank-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../tank/export/tank.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../tank/export/tank.png "$ROOT/spine-haxe/example/assets/"

cp -f ../vine/export/vine-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../vine/export/vine-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../vine/export/vine.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../vine/export/vine.png "$ROOT/spine-haxe/example/assets/"

cp -f ../owl/export/owl-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../owl/export/owl-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../owl/export/owl.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../owl/export/owl.png "$ROOT/spine-haxe/example/assets/"

cp -f ../stretchyman/export/stretchyman-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../stretchyman/export/stretchyman-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../stretchyman/export/stretchyman.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../stretchyman/export/stretchyman.png "$ROOT/spine-haxe/example/assets/"

cp -f ../mix-and-match/export/mix-and-match-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../mix-and-match/export/mix-and-match-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../mix-and-match/export/mix-and-match.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../mix-and-match/export/mix-and-match.png "$ROOT/spine-haxe/example/assets/"

cp -f ../celestial-circus/export/* "$ROOT/spine-haxe/example/assets/"

cp -f ../cloud-pot/export/cloud-pot.json "$ROOT/spine-haxe/example/assets/"
cp -f ../cloud-pot/export/cloud-pot.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../cloud-pot/export/cloud-pot.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../cloud-pot/export/cloud-pot.png "$ROOT/spine-haxe/example/assets/"

cp -f ../sack/export/sack-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../sack/export/sack-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../sack/export/sack.atlas "$ROOT/spine-haxe/example/assets/"
cp -f ../sack/export/sack.png "$ROOT/spine-haxe/example/assets/"

cp -f ../snowglobe/export/snowglobe-pro.json "$ROOT/spine-haxe/example/assets/"
cp -f ../snowglobe/export/snowglobe-pro.skel "$ROOT/spine-haxe/example/assets/"
cp -f ../snowglobe/export/snowglobe* "$ROOT/spine-haxe/example/assets/"

echo "--"
echo "Note regarding spine-xna and spine-unity:"
echo "Some textures (normalmap, emission, rim-mask) need manual update."
echo "Please update the following maps when an atlas update is needed:"
echo "[xna and unity]     'raptor/manual-maps' to match png in 'raptor/export/'"
echo "[unity only]   'stretchyman/manual-maps' to match png in 'stretchyman/export/'"
echo "If not updated, the old consistent file-set in the directory is used."
echo "--"
