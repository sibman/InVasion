extends TileMap

func _ready():
	if (Global.STORE_STATIC_ASSETS_COLLISION_SHAPES_IN_FILE):
		Global.saveTilemapCellsInFile(self)
