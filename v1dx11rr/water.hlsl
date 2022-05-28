


Texture2D colorMap : register(t0);
Texture2D normalMap : register(t1);
Texture2D displacementMap : register(t2);

SamplerState colorSampler : register(s0);

cbuffer cbChangerEveryFrame : register(b0)
{
	matrix worldMatrix;
};

cbuffer cbNeverChanges : register(b1)
{
	matrix viewMatrix;
};

cbuffer cbChangeOnResize : register(b2)
{
	matrix projMatrix;
};


cbuffer MovimientoWater : register(b3)
{
	float Movimiento;
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
	float Movimiento : TEXCOORD1;
	float4 clipspace : TEXCOORD2;
};

PS_Input VS_Main(VS_Input vertex)
{
	PS_Input vsOut = (PS_Input)0;

	vsOut.pos = mul(vertex.pos, worldMatrix);
	vsOut.pos = mul(vsOut.pos, viewMatrix);
	vsOut.pos = mul(vsOut.pos, projMatrix);

	vsOut.Movimiento = Movimiento;
	vsOut.clipspace = vsOut.pos;

	vsOut.tex0 = float2(vertex.tex0.x / 2.0 + 0.5, vertex.tex0.y / 2.0 + 0.5) * 8.0;



	return vsOut;
}

float4 PS_Main(PS_Input pix) : SV_TARGET
{
	

	float4 FinalWater = colorMap.Sample(colorSampler, float2(pix.tex0.x, pix.tex0.y + sin(pix.Movimiento)*.001));
	//float4 FinalWater = colorMap.Sample(colorSampler, reflectTexCoords);



	float3 ambient = float3(0.1f, 0.1f, 0.1f);

	float intensity = 0.4;
	
		//aqui se calcula la iluminacion difusa
		float4 textnorm = normalMap.Sample(colorSampler, float2(pix.tex0.x, pix.tex0.y + cos(pix.Movimiento)*.0022));
		float4 LuzAmbiental = float4(1.0, 1.0, 1.0, 1);
		float FA = .3;
		///////////////////////////////////////////////
		// aqui se desarrolla el elemento ambiental
		///////////////////////////////////////////////
		float4 AportAmb = LuzAmbiental * FA;
		//////////////////////////////////////////
		//aqui se desarrolla el elemento difuso //
		//////////////////////////////////////////
		float3 DirLuz = float3(30, 10, 30);
		float4 LuzDifusa = float4(1, 1, 1, 1);
		float FAD = .3;

		float3 bump = normalize(2.0 * textnorm - 1.0);

		float FALL = dot(normalize(bump), normalize(DirLuz));
		float4 AportLuzDif = saturate(LuzDifusa * FALL * FAD);
		FinalWater = FinalWater * (AportAmb + AportLuzDif);
		FinalWater.a = 0.1;
		//return FinalWater; //* (aportAmb + aportDif);
		return FinalWater;
}
