# ClobberParty
Sandbox brawler/party game prototype

# Notes
### Using KayKit animations and characters in UE5 using Blender
1. Import both the skeletal mesh for animations and character mesh to use for animation.
2. Join individual meshes to get the head, body, right arm, and left arm.
3. For each of the head, body, right arm, and left arm, add an Object Constract of a Child Of, targeting the respective bone.
4. Delete the original mesh for the skeletal mesh and reparent the character mesh to the armature (empty groups).
5. For each of the head, body, right arm, and left arm, respecify the Vertex Groups.
6. Join all four meshes.
7. Export selected as FBX at 50% scale with X Forward and Z Up.
