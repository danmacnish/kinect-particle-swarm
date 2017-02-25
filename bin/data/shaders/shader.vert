void main() {
    vec4 modifiedPos = gl_ModelViewProjectionMatrix * gl_Vertex;
    modifiedPos.x -= 425.0;
    modifiedPos.y -= 400.0;
    modifiedPos.y *= -1.0;
    gl_Position   =  modifiedPos;
	float size    = gl_Normal.x;
    gl_PointSize  = size;
    gl_FrontColor = gl_Color;

}