Texture2D textures;
SamplerState colorSampler : register(s0);

Texture2D texturaDia : register(t0);
Texture2D texturaNoche : register(t1);
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projMatrix;
	float4 valores;
};

cbuffer cbChangesOccasionally : register(b1)
{
	float blending;
};
struct VS_Input
{
	float4 pos : POSITION;
	float2 tex0 : TEXCOORD0;
};

struct PS_Input
{
	float4 pos : SV_POSITION;
	float2 tex0 : TEXCOORD0;
	float blending : TEXCOORD1;
};

PS_Input VS_Main(VS_Input vertex)
{
	PS_Input vsOut = (PS_Input)0;
	vsOut.pos = mul(vertex.pos, worldMatrix);
	vsOut.pos = mul(vsOut.pos, viewMatrix);
	vsOut.pos = mul(vsOut.pos, projMatrix);

	vsOut.tex0 = vertex.tex0;
	vsOut.blending = blending;

	return vsOut;
}

float4 PS_Main(PS_Input pix) : SV_TARGET
{
float4 dia;
	float4 noche;

	dia = texturaDia.Sample(colorSampler, pix.tex0);
	noche = texturaNoche.Sample(colorSampler, pix.tex0);


	float4 finalColor = dia * pix.blending + noche * (1 - pix.blending);

	return finalColor;
}