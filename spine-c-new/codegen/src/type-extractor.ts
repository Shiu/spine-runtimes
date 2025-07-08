import * as fs from 'fs';
import * as path from 'path';
import { execSync } from 'child_process';

const SPINE_CPP_PATH = path.join(__dirname, '../../../spine-cpp');
const EXTRACTOR_SCRIPT = path.join(SPINE_CPP_PATH, 'extract-spine-cpp-types.js');
const OUTPUT_FILE = path.join(__dirname, '../spine-cpp-types.json');
const HEADERS_DIR = path.join(SPINE_CPP_PATH, 'spine-cpp/include/spine');

/**
 * Checks if type extraction is needed based on file timestamps
 */
function isExtractionNeeded(): boolean {
    // If output doesn't exist, we need to extract
    if (!fs.existsSync(OUTPUT_FILE)) {
        console.log('spine-cpp-types.json not found, extraction needed');
        return true;
    }
    
    // Get output file timestamp
    const outputStats = fs.statSync(OUTPUT_FILE);
    const outputTime = outputStats.mtime.getTime();
    
    // Check all header files
    const headerFiles = fs.readdirSync(HEADERS_DIR)
        .filter(f => f.endsWith('.h'))
        .map(f => path.join(HEADERS_DIR, f));
    
    // Find newest header modification time
    let newestHeaderTime = 0;
    let newestHeader = '';
    
    for (const headerFile of headerFiles) {
        const stats = fs.statSync(headerFile);
        if (stats.mtime.getTime() > newestHeaderTime) {
            newestHeaderTime = stats.mtime.getTime();
            newestHeader = path.basename(headerFile);
        }
    }
    
    // If any header is newer than output, we need to extract
    if (newestHeaderTime > outputTime) {
        console.log(`Header ${newestHeader} is newer than spine-cpp-types.json, extraction needed`);
        return true;
    }
    
    console.log('spine-cpp-types.json is up to date');
    return false;
}

/**
 * Runs the extract-spine-cpp-types.js script to generate type information
 */
export function extractTypes(): void {
    if (!isExtractionNeeded()) {
        return;
    }
    
    console.log('Running type extraction...');
    
    try {
        // Run the extractor script
        const output = execSync(`node "${EXTRACTOR_SCRIPT}"`, {
            cwd: SPINE_CPP_PATH,
            encoding: 'utf8',
            maxBuffer: 10 * 1024 * 1024 // 10MB buffer for large output
        });
        
        // Write to output file
        fs.writeFileSync(OUTPUT_FILE, output);
        
        console.log(`Type extraction complete, wrote ${OUTPUT_FILE}`);
    } catch (error: any) {
        console.error('Failed to extract types:', error.message);
        throw error;
    }
}

/**
 * Loads the extracted type information
 */
export function loadTypes(): any {
    if (!fs.existsSync(OUTPUT_FILE)) {
        throw new Error(`Type information not found at ${OUTPUT_FILE}. Run extraction first.`);
    }
    
    return JSON.parse(fs.readFileSync(OUTPUT_FILE, 'utf8'));
}