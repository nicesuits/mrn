let component = ReasonReact.statelessComponent("IssueAdd");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      {ReasonReact.string("This is a placeholder for the issue add.")}
    </div>,
};