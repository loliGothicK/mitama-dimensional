extern crate clap;
#[allow(unused_imports)]
use clap::{App, AppSettings, Arg, SubCommand};

fn build_app() -> clap::App<'static, 'static> {
    let program = std::env::args()
        .nth(0)
        .and_then(|s| {
            std::path::PathBuf::from(s)
                .file_stem()
                .map(|s| s.to_string_lossy().into_owned())
        })
        .unwrap();

    App::new(program)
        .about("dimensional REPL impostor")
        .version("0.0.1")
        .author("Yuki Wada <yuki_wada@caddi.jp>")
        .arg(Arg::with_name("include")
            .short("I")
            .long("include")
            .takes_value(false))
}

fn main() {
    let matches = build_app().get_matches();
    let src_str = r#"
        #include "../include/quantity.hpp"
        #include "../include/si/all.hpp"
        #include "../include/math/all.hpp"
        #include "../include/arithmetic.hpp"
        #include "../include/comparison.hpp"
        #include "../include/io.hpp"
        #include "../include/prefix.hpp"
        #include "../include/refinment.hpp"
        usuig namespace mitama;
        int main(){
        #include "/tmp/relp.main"
        }
    "#;
    
}
