# Usage:
#   ./scripts/new_demo.ps1 -Chapter chapter_tree -Name binary_tree -Template with_common
#
# Template options:
#   basic, with_common, io

param(
    [Parameter(Mandatory = $true)]
    [string]$Chapter,

    [Parameter(Mandatory = $true)]
    [string]$Name,

    [ValidateSet('basic', 'with_common', 'io')]
    [string]$Template = 'basic'
)

$repoRoot = Split-Path -Parent $PSScriptRoot
$chapterDir = Join-Path $repoRoot $Chapter
if (-not (Test-Path $chapterDir)) {
    throw "Chapter directory not found: $Chapter"
}

$templateFile = switch ($Template) {
    'basic'       { 'main_basic.cpp' }
    'with_common' { 'main_with_common.cpp' }
    'io'          { 'main_io.cpp' }
}

$srcPath = Join-Path $repoRoot "templates/main/$templateFile"
$dstPath = Join-Path $chapterDir ($Name + '.cpp')

if (Test-Path $dstPath) {
    throw "File already exists: $dstPath"
}

Copy-Item -LiteralPath $srcPath -Destination $dstPath
Write-Host "Created:" $dstPath
