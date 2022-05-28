Texture2D colorMap : register(t0);
SamplerState colorSampler : register(s0);

cbuffer ConstantBuffer : register(b0)
{
    matrix worldMatrix;
};

struct VS_Input
{
    float4 pos : POSITION;
    float2 uv : TEXCOORD0;
    float3 normal : NORMAL;
};

struct PS_Input
{
    float4 pos : SV_POSITION;
    float2 uv : TEXCOORD0;
};

PS_Input VS_Main(VS_Input vertex)
{
    PS_Input psOut;
    psOut.pos = mul(vertex.pos, worldMatrix);
    psOut.uv = vertex.uv;
    
    return psOut;
}

float4 PS_Main(PS_Input input) : SV_Target
{
    float4 textura = colorMap.Sample(colorSampler, input.uv);
    clip(textura.a - 0.9f);
    return textura;
}